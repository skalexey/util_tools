export util_tools_deps="${HOME}/Projects"

function job()
{
	local THIS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
	source $THIS_DIR/os.sh

	if is_windows; then
		export util_tools_asio_path="C:/lib/asio-1.22.1/include"
	else
		export util_tools_asio_path="~/lib/asio-1.22.1/include"
	fi
}

job $@