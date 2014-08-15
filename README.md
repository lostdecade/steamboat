# Steamboat

A [Steamworks][0] binding for Node.js. Primarily targeting [node-webkit][1] and [Atom Shell][2].

Based on [Native Abstractions for Node.js][3] for maximum compatiblity with various versions of Node.js.

*NOTE: Steamboat is currently in the alpha/experimental phase of development. If you're looking for something more stable, please check out [greenworks][4] by [Greenheart Games][5].*

## Setup

* Download Steamworks SDK
* Copy or symlink to lib/steamworks
* DON'T commit Steamworks SDK files :)
* Run `npm install`

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
