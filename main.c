#include <EGL/egl.h>
#include <GLES/gl.h>
#include <android/log.h>
#include <jni.h>
#include <android/native_activity.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

#define NEW(type, count) ((type*)(malloc(sizeof(type)*count)))

void dlog(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	__android_log_vprint(ANDROID_LOG_DEBUG, "BARE_APK", fmt, args);
	va_end(args);
}

struct GlobalData
{
	uint8_t terminateApp;
	ANativeWindow* window;
};
static struct GlobalData gd = {};

static void onDestroy(ANativeActivity* activity)
{
	dlog("onDestroy\n");
	gd.terminateApp = 1;
};
static void onStart(ANativeActivity* activity)
{
	dlog("onStart\n");
	gd.terminateApp = 0;
};
static void onResume(ANativeActivity* activity)
{
	dlog("onResume\n");
};
static void* onSaveInstanceState(ANativeActivity* activity, size_t* outLen)
{
	dlog("onSaveInstanceState\n");
	outLen = 0;
	return NULL;
};
static void onPause(ANativeActivity* activity)
{
	dlog("onPause\n");
};
static void onStop(ANativeActivity* activity)
{
	dlog("onStop\n");
};
static void onConfigurationChanged(ANativeActivity* activity)
{
	dlog("onConfigurationChanged\n");
};
static void onLowMemory(ANativeActivity* activity)
{
	dlog("onLowMemory\n");
};
static void onWindowFocusChanged(ANativeActivity* activity, int focused)
{
	dlog("onWindowFocusChanged\n");
};
static void onNativeWindowCreated(ANativeActivity* activity, ANativeWindow* window)
{
	dlog("onNativeWindowCreated\n");
	gd.window = window;
};
static void onNativeWindowDestroyed(ANativeActivity* activity, ANativeWindow* window)
{
	dlog("onNativeWindowDestroyed\n");
	gd.window = NULL;
};
static void onInputQueueCreated(ANativeActivity* activity, AInputQueue* queue)
{
	dlog("onInputQueueCreated\n");
};
static void onInputQueueDestroyed(ANativeActivity* activity, AInputQueue* queue)
{
	dlog("onInputQueueDestroyed\n");
};
static void onNativeWindowRedrawNeeded(ANativeActivity* activity, ANativeWindow *window)
{
	dlog("onNativeWindowRedrawNeeded\n");
};

JNIEXPORT
void ANativeActivity_onCreate(ANativeActivity* activity, void* savedState, size_t savedStateSize)
{
	dlog("HELLO!\n");
	activity->callbacks->onDestroy = onDestroy;
    activity->callbacks->onStart = onStart;
    activity->callbacks->onResume = onResume;
    activity->callbacks->onSaveInstanceState = onSaveInstanceState;
    activity->callbacks->onPause = onPause;
    activity->callbacks->onStop = onStop;
    activity->callbacks->onConfigurationChanged = onConfigurationChanged;
    activity->callbacks->onLowMemory = onLowMemory;
    activity->callbacks->onWindowFocusChanged = onWindowFocusChanged;
    activity->callbacks->onNativeWindowCreated = onNativeWindowCreated;
    activity->callbacks->onNativeWindowDestroyed = onNativeWindowDestroyed;
    activity->callbacks->onInputQueueCreated = onInputQueueCreated;
    activity->callbacks->onInputQueueDestroyed = onInputQueueDestroyed;
	activity->callbacks->onNativeWindowRedrawNeeded = onNativeWindowRedrawNeeded;

	//ALooper *looper = ALooper_forThread();
	//ALooper_addFd(looper, android_app->uimsgread, LOOPER_ID_MAIN_THREAD, ALOOPER_EVENT_INPUT, process_ui, gapp);

	//while(false && !gd.terminateApp) {
	//	
	//}
}