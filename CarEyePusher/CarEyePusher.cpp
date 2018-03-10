/*
 * CarEyePusher.cpp
 *
 * Author: Wgj
 * Date: 2018-03-07 11:38
 *
 * CarEye推流器演示程序
 */

#include "stdafx.h"

using namespace std;

// CarEye服务器: 120.76.235.109
char ServerIP[] = "120.76.235.109";
const unsigned short ServerPort = 10554;
char SdpName[] = "careye_pusher.sdp";
char TestFile[] = "./test.mp4";

int main()
{
	// 启动文件推流, 全部推送
	int chn = CarEye_StartNativeFileRTSP(ServerIP, ServerPort, SdpName, TestFile, 12000, 32000);
	if (chn < 0)
	{
		printf("Start native file rtsp fail %d.", chn);
		return -1;
	}

	printf("Wait key stop channel[%d] rtsp...", chn);
	getchar();

	CarEye_StopNativeFileRTSP(chn);
	printf("Wait key exit program...");
	getchar();

	return 0;
}

