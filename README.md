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

Run `node-gyp rebuild`

To target other versions of Node:

node-gyp rebuild --target=v0.11.13

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
