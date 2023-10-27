#!/bin/bash

grep "$1" "$2" 2>/dev/null | wc -l
