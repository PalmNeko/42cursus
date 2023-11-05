#!/bin/sh

cd $(dirname "$0") || ( echo 'error change dir' && exit 1 )
cp -r ../Libft/submit/ ./submit/Libft
