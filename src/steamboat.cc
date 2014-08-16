#include <node.h>
#include <nan.h>
#include "../lib/steamworks/public/steam/steam_api.h"

using namespace std;
using namespace v8;

NAN_METHOD(SteamInit) {
	NanScope();

	bool success = SteamAPI_Init();

	NanReturnValue(NanNew<Boolean>(success));
}

NAN_METHOD(SteamShutdown) {
	NanScope();

	SteamAPI_Shutdown();
}

NAN_METHOD(SteamIsOverlayEnabled) {
	NanScope();
	bool enabled = SteamUtils()->IsOverlayEnabled();
	NanReturnValue(NanNew<Boolean>(enabled));
}

NAN_METHOD(SteamActivateGameOverlay) {
	NanScope();

	string dialogId(*NanUtf8String(args[0]));
	SteamFriends()->ActivateGameOverlay(dialogId.c_str());
}

NAN_METHOD(SteamSetAchievement) {
	NanScope();

	string achievementId(*NanUtf8String(args[0]));

	ISteamUserStats *userStats = SteamUserStats();
	bool success = userStats->SetAchievement(achievementId.c_str());
	if (success) {
		userStats->StoreStats();
	}

	NanReturnValue(NanNew<Boolean>(success));
}

void Init(Handle<Object> exports) {
	// Core
	exports->Set(
		NanNew<String>("init"),
		NanNew<FunctionTemplate>(SteamInit)->GetFunction()
	);
	exports->Set(
		NanNew<String>("shutdown"),
		NanNew<FunctionTemplate>(SteamShutdown)->GetFunction()
	);

	// Overlay
	exports->Set(
		NanNew<String>("isGameOverlayEnabled"),
		NanNew<FunctionTemplate>(SteamIsOverlayEnabled)->GetFunction()
	);
	exports->Set(
		NanNew<String>("activateGameOverlay"),
		NanNew<FunctionTemplate>(SteamActivateGameOverlay)->GetFunction()
	);

	// Achievements
	exports->Set(
		NanNew<String>("setAchievement"),
		NanNew<FunctionTemplate>(SteamSetAchievement)->GetFunction()
	);
}

NODE_MODULE(steamboat, Init)
