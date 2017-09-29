#!/bin/sh
#BHEADER**********************************************************************
# Copyright (c) 2008,  Lawrence Livermore National Security, LLC.
# Produced at the Lawrence Livermore National Laboratory.
# This file is part of HYPRE.  See file COPYRIGHT for details.
#
# HYPRE is free software; you can redistribute it and/or modify it under the
# terms of the GNU Lesser General Public License (as published by the Free
# Software Foundation) version 2.1 dated February 1999.
#
# $Revision$
#EHEADER**********************************************************************

testname=`basename $0 .sh`

# Echo usage information
case $1 in
   -h|-help)
      cat <<EOF

   **** Only run this script on one of the tux machines. ****

   $0 [-h|-help] {src_dir}

   where: -h|-help   prints this usage information and exits
          {src_dir}  is the hypre source directory
          

   This script runs a number of tests suitable for the tux machines.

   Example usage: $0 ../src

EOF
      exit
      ;;
esac

# Setup
test_dir=`pwd`
output_dir=`pwd`/$testname.dir
rm -fr $output_dir
mkdir -p $output_dir
src_dir=`cd $1; pwd`
shift

# Basic build and run tests
mo="-j test"
ro="-ams -ij -sstruct -struct"
eo=""

co=""
./test.sh basic.sh $src_dir -co: $co -mo: $mo
./renametest.sh basic $output_dir/basic-default

co="--enable-debug"
./test.sh basic.sh $src_dir -co: $co -mo: $mo -eo: $eo
./renametest.sh basic $output_dir/basic-debug1

co="--enable-debug --enable-global-partition"
RO="-fac"
./test.sh basic.sh $src_dir -co: $co -mo: $mo -ro: $RO -eo: $eo
./renametest.sh basic $output_dir/basic-debug2

co="--enable-debug CC=mpiCC"
./test.sh basic.sh $src_dir -co: $co -mo: $mo -ro: $ro -eo: $eo
./renametest.sh basic $output_dir/basic-debug-cpp

# co="--with-insure --enable-debug --with-print-errors"
# MO="test"
# ./test.sh basic.sh $src_dir -co: $co -mo: $MO -ro: $ro
# ./renametest.sh basic $output_dir/basic--with-insure1
# 
# co="--with-insure --enable-debug --enable-global-partition"
# MO="test"
# ./test.sh basic.sh $src_dir -co: $co -mo: $MO -ro: $ro
# ./renametest.sh basic $output_dir/basic--with-insure2

co="--enable-debug --with-print-errors"
./test.sh basic.sh $src_dir -co: $co -mo: $mo -ro: $ro -rt -valgrind
./renametest.sh basic $output_dir/basic--valgrind1

co="--enable-debug --enable-global-partition"
./test.sh basic.sh $src_dir -co: $co -mo: $mo -ro: $ro -rt -valgrind
./renametest.sh basic $output_dir/basic--valgrind2

co="--without-MPI"
./test.sh basic.sh $src_dir -co: $co -mo: $mo
./renametest.sh basic $output_dir/basic--without-MPI

co="--with-strict-checking"
./test.sh basic.sh $src_dir -co: $co -mo: $mo
./renametest.sh basic $output_dir/basic--with-strict-checking

co="--enable-shared"
./test.sh basic.sh $src_dir -co: $co -mo: $mo
./renametest.sh basic $output_dir/basic--enable-shared

co="--enable-bigint --enable-debug"
./test.sh basic.sh $src_dir -co: $co -mo: $mo -ro: $ro -eo: -bigint
./renametest.sh basic $output_dir/basic--enable-bigint

co="--enable-single --enable-debug"
./test.sh basic.sh $src_dir -co: $co -mo: $mo -ro: -single
./renametest.sh basic $output_dir/basic--enable-single

co="--enable-longdouble --enable-debug"
./test.sh basic.sh $src_dir -co: $co -mo: $mo -ro: -longdouble
./renametest.sh basic $output_dir/basic--enable-longdouble

co="--enable-maxdim=4 --enable-debug"
./test.sh basic.sh $src_dir -co: $co -mo: $mo -eo: -maxdim
./renametest.sh basic $output_dir/basic--enable-maxdim=4

co="--enable-complex --enable-maxdim=4 --enable-debug"
./test.sh basic.sh $src_dir -co: $co -mo: $mo -eo: -complex
# ignore complex compiler output for now
rm -fr basic.dir/make.???
grep -v make.err basic.err > basic.tmp
mv basic.tmp basic.err
./renametest.sh basic $output_dir/basic--enable-complex

# CMake build and run tests
mo="-j"
ro="-ams -ij -sstruct -struct"
eo=""

co=""
./test.sh cmake.sh $src_dir -co: $co -mo: $mo
./renametest.sh cmake $output_dir/cmake-default

co="-DCMAKE_BUILD_TYPE=Debug"
./test.sh cmake.sh $src_dir -co: $co -mo: $mo -ro: $ro
./renametest.sh cmake $output_dir/cmake-debug

co="-DHYPRE_NO_GLOBAL_PARTITION=OFF"
./test.sh cmake.sh $src_dir -co: $co -mo: $mo
./renametest.sh cmake $output_dir/cmake-global-partition

co="-DHYPRE_SEQUENTIAL=ON"
./test.sh cmake.sh $src_dir -co: $co -mo: $mo
./renametest.sh cmake $output_dir/cmake-sequential

co="-DHYPRE_SHARED=ON"
./test.sh cmake.sh $src_dir -co: $co -mo: $mo
./renametest.sh cmake $output_dir/cmake-shared

co="-DHYPRE_BIGINT=ON"
./test.sh cmake.sh $src_dir -co: $co -mo: $mo -ro: $ro
./renametest.sh cmake $output_dir/cmake-bigint

co="-DHYPRE_SINGLE=ON"
./test.sh cmake.sh $src_dir -co: $co -mo: $mo -ro: -single
./renametest.sh cmake $output_dir/cmake-single

co="-DHYPRE_LONG_DOUBLE=ON"
./test.sh cmake.sh $src_dir -co: $co -mo: $mo -ro: -longdouble
./renametest.sh cmake $output_dir/cmake-longdouble

# cmake build doesn't currently support maxdim
# cmake build doesn't currently support complex

# Test linking for different languages
link_opts="all++ all77"
for opt in $link_opts
do
   output_subdir=$output_dir/link$opt
   mkdir -p $output_subdir
   ./test.sh link.sh $src_dir $opt
   mv -f link.??? $output_subdir
done

# Check for 'int', 'double', and 'MPI_'
./test.sh check-int.sh $src_dir
mv -f check-int.??? $output_dir
./test.sh check-double.sh $src_dir
mv -f check-double.??? $output_dir
./test.sh check-mpi.sh $src_dir
mv -f check-mpi.??? $output_dir

# Echo to stderr all nonempty error files in $output_dir
for errfile in $( find $output_dir ! -size 0 -name "*.err" )
do
   echo $errfile >&2
done
