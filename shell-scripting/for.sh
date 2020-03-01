#!/usr/bin/env bash

NAMES=$@

for NAME in $NAMES
do
  if [ $NAME = "tracy" ]
  then
    break
  fi

  if [ $NAME = "lazy" ]
  then
    continue
  fi
  echo "HELLO $NAME"
done

echo "loop finished"
exit 0