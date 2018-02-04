#!/bin/sh


echo "\n----------------------------------------------------"
echo "*****Current time and date*****"
date

echo "\n*****Process ID Information*****"
ps -aux | grep -i "cron"

echo "\n*****User ID Information******"
id

echo "\nin place of the system call"

echo "----------------------------------------------------"
