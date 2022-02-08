//I am a newer for C++,so this is a full of problems,so  i am very thanks for every guys who point out the problems.thanks before.

#include "windows.h"
#include "iostream"
#include "cstring"
#include "mmsystem"

/*
  Windows if
  add code "#parama comment(lib,"winmm.lib")"
  may be "#parama warning(disable:"4996")" is needed.
  don't forget to add static libary "winmm.lib" to link libary file.
*/

/*
  if you are coding with MinGw64.if you always use command line mode, alright,anythings, don't forget to add compile parameter "lwinmm" or add libary file "libwinmm.a" 
*/

using namespace std;

void loop(char ar[25]);
int _Compare(char *ar1, char *ar2);
// C:/Users/XiaYuqiao/Downloads/planefight/mainbgm.mp3
char msg[25];
char initPath[255] = "open ";
char aBgm[25] = " alias BGM", quit[25]="quit",resume[25]="resume",pause[25]="pause",cutsong[25]="cutsong";
//char sBgm[25]="stop BGM";
char open[25] = "open ", play[25] = "play";
char inpath[230];

int main()
{
    cout << "Enter your music file path to submit to the player:";
    cin >> inpath;
    strcat(initPath, inpath);
    strcat(initPath, aBgm);
    cout << "Enter \"play\" to play music : ";
    cin >> msg;
    loop(msg);
    return 0;
}

void loop(char ar[25])
{
    if (_Compare(ar, play) == 0)
    {
        mciSendStringA(reinterpret_cast<LPSTR>(initPath), 0, 0, 0);
        mciSendStringA("play BGM repeat", 0, 0, 0);
        while (1)
        {
            memset(ar, '\0', sizeof(ar));
            cin >> ar;
            if (_Compare(ar, quit) == 0)
            {
                cout << "Bye!";
                mciSendStringA("close BGM", 0, 0, 0);
                exit(EXIT_SUCCESS);
            }
            else
            {
                loop(ar);
            }
        };
    }
    else if (_Compare(ar, quit) == 0)
    {
        cout << "Bye!";
        mciSendStringA("close BGM", 0, 0, 0);
        exit(EXIT_SUCCESS);
    }
    else if (_Compare(ar, pause) == 0)
    {
        cout << "Playing paused...Waiting for instructions \"resume\":";
        mciSendStringA("stop BGM", 0, 0, 0);
        memset(ar, '\0', sizeof(ar));
        cin >> ar;
        loop(ar);
    }
    else if (_Compare(ar, resume) == 0)
    {
        cout << "Play continues...";
        mciSendStringA("resume BGM", 0, 0, 0);
        memset(ar, '\0', sizeof(ar));
        cin >> msg;
        loop(ar);
    }
    else if (_Compare(ar, cutsong) == 0)
    {
        cout << "Enter a new play file:";
        cin >> inpath;
        mciSendStringA("close BGM", 0, 0, 0);
        memset(initPath, '\0', sizeof(initPath));
        memset(ar, '\0', sizeof(ar));
        for (int i = 0; i < sizeof(open); i++)
        {
            initPath[i] = open[i];
        }
        strcat(initPath, inpath);
        strcat(initPath, aBgm);
        cout << "Retype \"play\" to play the new music file:";
        cin >> ar;
        loop(ar);
    }
    else
    {
        cout << "Not command parameter!" << endl << "Please try it again:" << endl;
        memset(ar, '\0', sizeof(ar));
        cin >> ar;
        loop(ar);
    }
}

int _Compare(char *ar1, char *ar2)
{
    for (int i = 0; i < sizeof(ar2); i++)
    {
        if (ar1[i] == ar2[i])
        {
            continue;
        }
        else {
            return -1;
        }
    }
    return 0;
}
