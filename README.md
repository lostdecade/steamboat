# Steamboat

A [Steamworks][0] binding for Node.js. Primarily targeting [node-webkit][1] and [Atom Shell][2].

Based on [Native Abstractions for Node.js][3] for maximum compatiblity with various versions of Node.js.

*NOTE: Steamboat is currently in the alpha/experimental phase of development. If you're looking for something more stable, please check out [greenworks][4] by [Greenheart Games][5].*

## Setup

First and foremost, you'll need to have access to the Steamworks SDK. Download the SDK from Valve and either copy or symlink it to `lib/steamworks` at the root of Steamboat. To be clear: the `lib` folder should be a sibling to `src`.

Don't commit the Steamworks SDK files to source control or distribute them with your game. You'll only need to ship a few specific files from the `redistributable_bin` folder which we'll cover later.

Lastly, run `npm install` at the root in order to pull in the Node.js dependencies.

## Build

You'll need [node-gyp][6] in order to build. node-gyp has some of its own requirements, such as Python and Visual Studio on Windows. See its [installation instructions][8] for more info.

```
node-gyp rebuild --arch=ia32 --target=0.11.13
```

The `--target` parameter can be used to target a different version of Node, e.g. 0.10.x. The `--arch` paramter can be used to build for 32-bit (ia32) vs 64-bit (x64) architectures.

### Building for node-webkit

node-webkit requires its own build tool, [nw-gyp][7]. With nw-gyp, the target version becomes the version of *node-webkit* you'd like to target instead of the version of Node.

```
nw-gyp rebuild --arch=ia32 --target=0.10.2
```

### Building for Atom Shell

Atom Shell also [requires some special tweaks][9] in order to properly build native modules. The development headers must be fetched from a different location. This can be done by using the `--dist-url` paramter:

```
node-gyp rebuild --arch=ia32 --target=0.11.13 --dist-url=https://gh-contractor-zcbenz.s3.amazonaws.com/atom-shell/dist
```

If the previous files for a specific version have already been fetched from the default location, you'll need to remove them first:

```
node-gyp remove 0.11.13
```

## Distribution

TODO: Which Steam redist libs to ship and where
TODO: Where to put steam_appid.txt for node-webkit and Atom Shell

## API

### init()

Must be called first. Returns true/false if initialization succeeded/failed.

```
var success = steamboat.init();
```

### shutdown()

Call when your app is shutting down.

```
steamboat.shutdown();
```

### isGameOverlayEnabled()

Returns true/false if the Steam overlay is enabled/disabled.

```
var enabled = steamboat.isGameOverlayEnabled();
```

### activateGameOverlay(dialogId)

Triggers the Steam overlay to display the specified dialog. Possible dialog values are:

* Friends
* Community
* Players
* Settings
* OfficialGameGroup
* Achievements

```
steamboat.activateGameOverlay("Achievements");
```

### setAchievement(achievementId)

```
steamboat.setAchievement("perfectScore");
```

[0]: http://www.steampowered.com/steamworks/
[1]: https://github.com/rogerwang/node-webkit
[2]: https://github.com/atom/atom-shell
[3]: https://github.com/rvagg/nan
[4]: https://github.com/greenheartgames/greenworks
[5]: http://www.greenheartgames.com
[6]: https://github.com/TooTallNate/node-gyp
[7]: https://github.com/rogerwang/nw-gyp
[8]: https://github.com/TooTallNate/node-gyp#installation
[9]: https://github.com/atom/atom-shell/blob/master/docs/tutorial/use-native-node-modules.md
