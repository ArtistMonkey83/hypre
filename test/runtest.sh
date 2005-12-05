#!/bin/sh
#BHEADER***********************************************************************
# (c) 2000   The Regents of the University of California
#
# See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
# notice, contact person, and disclaimer.
#
# $Revision$
#EHEADER***********************************************************************

# globals
BatchMode=0
NoRun=0
JobCheckInterval=10      # sleep time between jobs finished check
InputString=""
RunString=""
ExecFileNames=""         #string of executable file names used
TestDirNames=""          #string of names of TEST_* directories used

function usage ()
{
   printf "\n"
   printf "$0 [-n|-norun] [-h|-help] [-t|-trace] {test_path}/{test_name}.sh\n"
   printf "\n"
   printf " where: {test_path} is the directory path to the test script;\n"
   printf "        {test_name} is a user defined name for the test script\n"
   printf "\n"
   printf "        -help          prints this usage information and exits\n"
   printf "        -norun         turn off execute, echo mode\n"
   printf "        -trace         echo each command\n"
   printf "\n"
   printf " This is the hypre test driver script.  It is run stand-alone\n"
   printf " or by the autotest regression test script.  It is assumed that\n"
   printf " there are test directories test/TEST_{solver} that contain:\n" 
   printf "   1. Individual test scripts named {test_name}.jobs that provide\n"
   printf "         the mpirun execution syntax\n"
   printf "   2. Test run output files named {test_name}.out.{number}\n"
   printf "   3. Individual scripts to compare (usually using diff) output\n"
   printf "         files from corresponding {test_name}.jobs scripts\n"
   printf "\n"
   printf " Ideally, the *.jobs and *.sh scripts can be run as stand-alone\n"
   printf " shell script files.  A test is considered successful when there \n"
   printf " are no error files generated by the *.sh scripts.\n"
   printf "\n"
   printf " NOTE: This script knows about most of the ASC machines\n"
   printf " and will automatically use the Livermore Computing Resource\n" 
   printf " Management (LCRM) batch system if required.\n"
   printf "\n"
   printf " Example usage: ./runtest.sh -t TEST_sstruct/*.sh\n"
   printf "\n"
}

# generate default mpirun or psub command based on the first 4 characters of
# the platform hostname

function MpirunString
{
   HOST=`hostname|cut -c1-4`
   POE_NUM_PROCS=1
   POE_NUM_NODES=1
   CPUS_PER_NODE=1
   case $HOST in
      gps*) MPIRUN=`type mpirun|sed -e 's/^.* //'`
         RunString="$MPIRUN $*"
         ;;
      fros*) CPUS_PER_NODE=16
         POE_NUM_PROCS=$2
         POE_NUM_NODES=`expr $POE_NUM_PROCS + $CPUS_PER_NODE - 1`
         POE_NUM_NODES=`expr $POE_NUM_NODES / $CPUS_PER_NODE`
         shift
         shift
         RunString="poe $* -procs $POE_NUM_PROCS -nodes $POE_NUM_NODES"
         ;;
      uv*) CPUS_PER_NODE=8
         POE_NUM_PROCS=$2
         POE_NUM_NODES=`expr $POE_NUM_PROCS + $CPUS_PER_NODE - 1`
         POE_NUM_NODES=`expr $POE_NUM_NODES / $CPUS_PER_NODE`
         shift
         shift
         RunString="poe $* -procs $POE_NUM_PROCS -nodes $POE_NUM_NODES"
         ;;
      peng*) shift
         RunString="srun -n$*"
         ;;
      alc*) shift
         RunString="srun -n$*"
         ;;
      mcr*) shift
         RunString="srun -n$*"
         ;;
      ilx*) MPIRUN=`type mpirun|sed -e 's/^.* //'`
         RunString="$MPIRUN $*"
         ;;
      tux*) MACHINES_FILE="hostname"
         if [ ! -f $MACHINES_FILE ] ; then
            hostname > $MACHINES_FILE
         fi
         MPIRUN=`type mpirun|sed -e 's/^.* //'`
         RunString="$MPIRUN -machinefile $MACHINES_FILE $*"
         ;;
      vivi*) MPIRUN=`type mpirun|sed -e 's/^.* //'`
         RunString="$MPIRUN $*"
         ;;
      ript*) MPIRUN=`type mpirun|sed -e 's/^.* //'`
         RunString="$MPIRUN $*"
         ;;
      *) MPIRUN=`type mpirun|sed -e 's/^.* //'`
         RunString="$MPIRUN $*"
         ;;
   esac
}

# determine if host can process psub (batch queues)

function CheckBatch
{
   BATCH_MODE=0
   HOST=`hostname|cut -c1-4`
   case $HOST in
      gps*) BATCH_MODE=1
         ;;
      fros*) BATCH_MODE=1
         ;;
      uv*) BATCH_MODE=1
         ;;
      peng*) BATCH_MODE=1
         ;;
      alc*) BATCH_MODE=1
         ;;
      mcr*) BATCH_MODE=1
         ;;
      ilx*) BATCH_MODE=1
         ;;
      *) BATCH_MODE=0
         ;;
   esac
   return $BATCH_MODE
}

# determine if host can process script file directly

function CheckSimpleRun
{
   BATCH_MODE=0
   HOST=`hostname|cut -c1-4`
   case $HOST in
      vivi*) BATCH_MODE=1
         ;;
      ript*) BATCH_MODE=1
         ;;
      *) BATCH_MODE=0
         ;;
   esac
   return $BATCH_MODE
}

# determine the "number of nodes" desired by dividing the "number of processes"
# by the "number of CPU's per node" which can't be determined dynamically (real
# ugly hack)

function CalcNodes
{
   NUM_PROCS=1
   NUM_NODES=1
   CPUS_PER_NODE=1
   HOST=`hostname|cut -c1-4`
   case $HOST in
      gps*) CPUS_PER_NODE=4
         ;;
      fros*) CPUS_PER_NODE=16
         ;;
      uv*) CPUS_PER_NODE=8
         ;;
      peng*) CPUS_PER_NODE=2
         ;;
      alc*) CPUS_PER_NODE=2
         ;;
      mcr*) CPUS_PER_NODE=2
         ;;
      ilx*) CPUS_PER_NODE=2
         ;;
      *) CPUS_PER_NODE=1
         ;;
   esac

   while [ "$1" ]
   do
      case $1 in
         -n*) NUM_PROCS=$2
            NUM_NODES=`expr $NUM_PROCS + $CPUS_PER_NODE - 1`
            NUM_NODES=`expr $NUM_NODES / $CPUS_PER_NODE`
            return $NUM_NODES
            ;;
         *) shift
            ;;
      esac
   done
   return 1
}

# extract the "number of processes|task"

function CalcProcs
{
   while [ "$1" ]
   do
      case $1 in
         -n*) return $2
            ;;
         *) shift
            ;;
      esac
   done
   return 1
}

# check the path to the executable if the executable exists; save the name to
# ExecFileNames

function CheckPath
{
   while [ "$1" ]
   do
      case $1 in
         -n*) EXECFILE=$3
            if [ -x $StartDir/$EXECFILE ] ; then
               cp -f $StartDir/$EXECFILE $EXECFILE
               ExecFileNames="$ExecFileNames $EXECFILE"
               return 0
            else
               echo "Cannot find executable!!!"
               return 1
            fi
            return 0
            ;;
         *) shift
            ;;
      esac
   done
   return 1
}

function ExecuteScripts
{
   StartDir=$1
   WorkingDir=$2
   InputFile=$3
   SavePWD=`pwd`
   cd $WorkingDir
   ./$InputFile.jobs > $InputFile.err 2>&1 
   ./$InputFile.sh  >> $InputFile.err 2>&1
   cd $SavePWD
}

# initialize the common part of the " PsubCmd" string, ugly global vars!
# global "RunName" is assumed to be predefined

function PsubCmdStub
{
   CalcNodes "$@"
   NumNodes=$?
   CalcProcs "$@"
   NumProcs=$?
   HOST=`hostname|cut -c1-4`
   case $HOST in
      gps*) PsubCmd="psub -c gps320 -b casc -r $RunName -cpn $NumProcs"
         ;;
      fros*) PsubCmd="psub -c frost,pbatch -b a_casc -nettype css0 -r $RunName"
         PsubCmd="$PsubCmd -ln $NumNodes -g $NumProcs"
         ;;
      uv*) PsubCmd="psub -c uv,pbatch -b a_casc -nettype css0 -r $RunName"
         PsubCmd="$PsubCmd -ln $NumNodes -g $NumProcs"
         ;;
      peng*) PsubCmd="psub -c pengra,pbatch -b casc -r $RunName -ln $NumProcs"
         PsubCmd="$PsubCmd -standby"
         ;;
      alc*) PsubCmd="psub -c alc,pbatch -b casc -r $RunName -ln $NumProcs"
         PsubCmd="$PsubCmd -standby"
         ;;
      mcr*) PsubCmd="psub -c mcr,pbatch -b casc -r $RunName -ln $NumProcs"
         PsubCmd="$PsubCmd -standby"
         ;;
      ilx*) PsubCmd="psub -c ilx -b casc -r $RunName -cpn $NumProcs"
         ;;
      *) PsubCmd="psub -b casc -r $RunName -ln $NumProcs"
         ;;
   esac
}

# read job file line by line saving arguments

function ExecuteJobs
{
   StartDir=$1
   WorkingDir=$2
   InputFile=$3
   ReturnFlag=0              # error return flag
   BatchFlag=0               # #BATCH option detected flag 
   BatchCount=0              # different numbering for #Batch option
   PrevPid=0
   SavePWD=`pwd`
   cd $WorkingDir

   # open *.jobs files for reading
   while read InputLine
   do
      case $InputLine in
         "#BATCH"*) BatchFlag=1
            BatchFile=""
            ;;

         "#END"*) BatchFlag=0
            chmod +x $BatchFile
            PsubCmd="$PsubCmd -o $OutFile -e $ErrFile `pwd`/$BatchFile"
            if [ "$NoRun" -eq 0 ] ; then
               CmdReply=`$PsubCmd`
            fi
            PrevPid=`echo $CmdReply | cut -d \  -f 2`
            while [ "`pstat | grep $PrevPid`" ]
            do
               sleep $JobCheckInterval      # global, see runtest.sh
            done
            BatchFile=""
            ;;

         *mpirun*)
            RunCmd=`echo $InputLine| sed -e 's/^[ \t]*mpirun[ \t]*//'` 
            RunCmd=`echo $RunCmd | sed -e 's/[ \t]*>.*$//'`
            OutFile=`echo $InputLine | sed -e 's/^.*>//'`
            OutFile=`echo $OutFile | sed -e 's/ //g'`
            ErrFile=`echo $OutFile | sed -e 's/\.out\./.err./'`
            RunName=`echo $OutFile | sed -e 's/\.out.*$//'`
            CheckPath $RunCmd               # check path to executable
            if [ "$?" -gt 0 ] ; then
               cat >> $RunName.err <<- EOF
Executable doesn't exist command: 
$InputLine 
EOF
               ReturnFlag=1
               break
            fi
            MpirunString $RunCmd            # construct "RunString"
            if [ "$BatchMode" -eq 0 ] ; then
               sh ${RunString} > $OutFile 2> $ErrFile </dev/null
            else
               if [ "$BatchFlag" -eq 0 ] ; then
                  BatchFile=`echo $OutFile | sed -e 's/\.out\./.batch./'`
                  cat > $BatchFile <<- EOF 
#!/bin/sh
cd `pwd`
${RunString}
EOF
                  chmod +x $BatchFile
                  PsubCmdStub ${RunCmd}
                  PsubCmd="$PsubCmd -o $OutFile -e $ErrFile `pwd`/$BatchFile"
                  if [ "$NoRun" -eq 0 ] ; then
                     CmdReply=`$PsubCmd`
                  fi
                  PrevPid=`echo $CmdReply | cut -d \  -f 2`
                  while [ "`pstat | grep $PrevPid`" ]
                  do
                     # JobCheckInterval is a global variable
                     sleep $JobCheckInterval
                  done
               else                          # BatchFlag set
                  if [ "$BatchFile" -eq "" ] ; then
                     BatchFile=$InputFile.batch.$BatchCount
                     BatchCount=BatchCount+1
                     cat > $BatchFile <<- EOF
#!/bin/sh
cd `pwd`
${RunString}
EOF
                  else
                     cat >> $BatchFile <<- EOF
${RunString}
EOF
                  fi
                  PsubCmdStub ${RunCmd}     # construct a PsubCmd string
               fi                           # BatchFlag set
            fi                              # BatchMode set
            ;;

         *"#"*) :
            ;; 

         *)
            NOTBLANK=`echo $InputLine | sed 's/[ \n\t]//g'`
            if [ "$NOTBLANK" ] ; then
               echo "Found something unexpected in $WorkingDir/$InputFile.jobs"
               echo "--> $InputLine"
               exit 1
            fi
            ;;
      esac
   done < $InputFile.jobs           # done with open *.jobs file for reading
   cd $SavePWD
   return $ReturnFlag
}

function ExecuteTest
{
   StartDir=$1
   WorkingDir=$2
   InputFile=$3
   SavePWD=`pwd`
   cd $WorkingDir
   (cat $InputFile.err.* > $InputFile.err)
   (./$InputFile.sh     >> $InputFile.err 2>&1 &) 
   cd $SavePWD
}

function PostProcess
{
   StartDir=$1
   WorkingDir=$2
   InputFile=$3
   SavePWD=`pwd`
   cd $WorkingDir
   if [ "$BatchMode" -eq 0 ] ; then
      if [ -f purify.log ] ; then
         mv purify.log $InputFile.purify.log
         grep -i hypre_ $InputFile.purify.log >> $InputFile.err
      elif [ -f insure.log ] ; then
         mv insure.log $InputFile.insure.log
         grep -i hypre_ $InputFile.insure.log >> $InputFile.err
      fi
   fi
   cd $SavePWD
}

# removes executable and hostname files from all TEST_* directories

function CleanUp
{
   if [ "$BatchMode" -eq 0 ] ; then
      for i in $TestDirNames
      do 
         for j in $ExecFileNames
         do 
            ExecuteFile=$i/$j
            if [ -x $ExecuteFile ] ; then
               rm -f $ExecuteFile
               rm -f hostname
            fi
         done
         ExecuteFile=$i/hostname
         if [ -f $ExecuteFile ] ; then
            rm -f $ExecuteFile
         fi
      done
   fi
}

# process files

function StartCrunch
{
   CheckSimpleRun                # check if host can just execute scripts
   RtnCode=$?
   if [ "$RtnCode" -ne 0 ] ; then
      ExecuteScripts "$@"
      RtnCode=$?
   else
      ExecuteJobs "$@"
      RtnCode=$?
      if [ "$RtnCode" -eq 0 ] ; then
         ExecuteTest "$@"
         RtnCode=$?
      fi
   fi
   if [ "$RtnCode" -eq 0 ] ; then
      PostProcess "$@"
   fi
}

# main

while [ "$*" ]
do
   case $1 in
      -h|-help)
         usage
         exit
         ;;
      -n|-norun)
         NoRun=1
         shift
         ;;
      -t|-trace)
         set -xv
         shift
         ;;
      *) InputString=$1
         if [ "$InputString" ] ; then
            if [ -r $InputString ] ; then
               FilePart=`basename $InputString .sh`
               DirPart=`dirname $InputString`
               CurDir=`pwd`
               TestDirNames="$TestDirNames $DirPart"
               if [ "$BatchMode" -eq 0 ] ; then      # machine DCSP capable
                  CheckBatch
                  BatchMode=$?
               fi
               if [ -r $DirPart/$FilePart.jobs ] ; then
                  # strict serial execution
                  StartCrunch $CurDir $DirPart $FilePart
               else
                  printf "%s: test command file %s/%s.jobs does not exist\n" \
                     $0 $DirPart $FilePart
                  exit 1
               fi
            else
               printf "%s: test command file %s does not exist\n" \
                  $0 $InputString
               printf "can not find .sh file\n"
               exit 1
            fi
         else
            printf "%s: Strange input parameter=%s\n" $0 $InputString
            exit 1
         fi
         shift
         ;;
   esac
done
CleanUp $TestDirNames $ExecFileNames
