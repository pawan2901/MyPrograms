#find ./TFolder/* -type d -ctime 0 -exec rm -rf {} \;
find ./TFolder/* -type d -ctime 0 | xargs rm -rf;

