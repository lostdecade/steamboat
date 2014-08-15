#include <node.h>
#include <nan.h>
#include "../lib/steamworks/public/steam/steam_api.h"

NAN_METHOD(SteamInit) {
	NanScope();

	bool success = SteamAPI_Init();

	NanReturnValue(NanNew<v8::Boolean>(success));
}

void Init(v8::Handle<v8::Object> exports) {
	exports->Set(
		NanNew<v8::String>("init"),
		NanNew<v8::FunctionTemplate>(SteamInit)->GetFunction()
	);
}

NODE_MODULE(steamboat, Init)
