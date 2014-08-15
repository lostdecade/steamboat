{
	"targets": [
		{
			"target_name": "steamboat",
			"sources": [
				"src/steamboat.cc"
			],
			"include_dirs": [
				"<!(node -e \"require('nan')\")"
			],
			"link_settings": {
				"ldflags": [
					"-L$(CURDIR)/../lib/steamworks/redistributable_bin/osx32"
				],
				"libraries": [
					"$(CURDIR)/../lib/steamworks/redistributable_bin/osx32/libsteam_api.dylib"
				]
			}
		}
	]
}
