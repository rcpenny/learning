#!/usr/bin/env bash

NAMES=$@

for NAME in $NAMES
do
  echo "HELLO $NAME"
done

echo "loop finished"
exit 0