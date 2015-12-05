#! /bin/sh
## File:        copy.sh
## Package:     Babel binary
## Copyright:   (c) 2000-2001 The Regents of the University of California
## Revision:    $Revision: 1.10 $
## Modified:    $Date: 2006/08/29 22:29:10 $
## Description: copy files for build: copy.sh SRCDIR DSTDIR files...

srcdir=$1 ; shift
dstdir=$1 ; shift

if test "X$srcdir" != "X$dstdir"; then
  for f in $*; do
    echo cp $srcdir/$f $dstdir
    cp $srcdir/$f $dstdir
  done
fi

for f in $*; do
  echo chmod +w $dstdir/$f
  chmod +w $dstdir/$f
done

exit 0
