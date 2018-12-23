#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
using namespace std;
class MediaPlayer
{
virtual void play(string type, string file){}
};
class AdvanceMediaPlayer
{
public:
	virtual void playVLC(string file) {}
	virtual void playMP4(string file){}
};
class VLCPlayer : public AdvanceMediaPlayer
{
	void playVLC(string file) { cout << "Playing vlc media "<<file << endl; }
};
class MP4Player : public AdvanceMediaPlayer
{
	void playMP4(string file) { cout << "Playing MP4 media "<<file << endl; }
};
class MediaAdapter : public MediaPlayer
{
public:
	AdvanceMediaPlayer* advanceMusicPlayer;
	MediaAdapter(string mediaType)
	{
		if (mediaType == "vlc") advanceMusicPlayer = new VLCPlayer;
		else if (mediaType == "mp4") advanceMusicPlayer = new MP4Player;
	}
	void play(string type, string file)
	{
		if (type == "vlc") { advanceMusicPlayer->playVLC(file); }
		else if (type == "mp4") { advanceMusicPlayer->playMP4(file); }
	}
};
class AudioPlayer :public MediaPlayer
{
	MediaAdapter* mediaAdapter;
public:
	void play(string type, string file)
	{
		if (type == "mp3") { cout << "playing mp3 media " << file << endl; }
		else if (type == "vlc" || type == "mp4") { mediaAdapter = new MediaAdapter(type);
		mediaAdapter->play(type, file);
		}
		else cout << "File format not supported " << endl;
	}
};
void AdapterPatternDemo()
{
	AudioPlayer ap;
	ap.play("vlc", "abc.vlc");
	ap.play("mp3", "abc.mp3");
	ap.play("avi", "abc.avi");
}
