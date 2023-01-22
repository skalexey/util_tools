#!/bin/bash

function deps_scenario()
{
	local THIS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
    source $THIS_DIR/dependencies.sh
    source $THIS_DIR/deps_config.sh

    download_dependency "$vlDirRel" "$depsLocationFull" "git@github.com:skalexey/VL.git"
    download_dependency "$rapidjsonDirRel" "$depsLocationFull" "https://github.com/Tencent/rapidjson.git"
}

deps_scenario $@
