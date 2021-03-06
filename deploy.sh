#!/bin/bash

source os.sh

if is_mac; then
	deploy_dir="/usr/local/bin"
else
	deploy_dir="/usr/bin"
fi

cp Build-cmake/numbers_transform/Release/numbers_transform "$deploy_dir"
cp Build-cmake/numbers_mixer/Release/numbers_mixer "$deploy_dir"
cp Build-cmake/numbers_average/Release/numbers_average "$deploy_dir"

[ $? -ne 0 ] && echo " --- Errors during deploying at '$deploy_dir'" || echo " --- Deployed successfully at '$deploy_dir'"
