{
	"variables": {
		"redist_path": "lib/steamworks/redistributable_bin/"
	},
	"conditions": [
		['OS=="win"', {
			"variables": {
				"module_suffix": "win32",
				"redist_os_path": "",
				"redist_lib": "steam_api.lib",
				"base_path": "$(CURDIR)../"
			}
		}],
		['OS=="mac"', {
			"variables": {
				"module_suffix": "osx32",
				"redist_os_path": "osx32/",
				"redist_lib": "libsteam_api.dylib",
				"base_path": "$(CURDIR)/../"
			}
		}]
	],
	"targets": [
		{
			"target_name": "steamboat-<(module_suffix)",
			"sources": [
				"src/steamboat.cc"
			],
			"include_dirs": [
				"<!(node -e \"require('nan')\")"
			],
			"link_settings": {
				"ldflags": [
					"-L<(base_path)<(redist_path)<(redist_os_path)"
				],
				"libraries": [
					"<(base_path)<(redist_path)<(redist_os_path)<(redist_lib)"
				]
			}
		}
	]
}
