/*
  I am a newer for C++,so this is a full of problems,so  i am very thanks for every guys who point out the problems.thanks before.
*/


/*
  VC++ if:
  add code "#parama comment(lib,"winmm.lib")"
  may be "#parama warning(disable:"4996")" is needed.
  don't forget to add static libary "winmm.lib" to link libary file.

  if you are coding with MinGw64.if you always use command line mode, alright,anythings, don't forget to add compile parameter "-lwinmm"  to link static libary. 
  
  Code is not commented,too simple to view.
  
  file path such as C:\User\xxx\Music\xxx.(mp3 or wav) etc. I don't kown why it couldn't play .wav file in my Windows 11 Lap-top,so yours could check the code to find what different,thanks.
*/

#include "windows.h"
#include "iostream"
#include "cstring"
#include "mmsystem.h"


using namespace std;

char msg[25];
void loop(char *const ar);
int compare(const char *ar1,const char *ar2);

char initPath[255] = "open ",aBgm[11] = " alias BGM", quit[5]="quit",resume[7]="resume";
char pause[6]="pause",cutsong[8]="cutsong",open[6] = "open ", play[25] = "play",inpath[230] = "";

int main()
{
    cout << "Enter your music file path to submit to the player:";
    cin >> inpath;
    strcat(initPath, inpath);
    strcat(initPath, aBgm);
    cout << "Enter \"play\" to play music\n: ";
    cin >> msg;
    loop(msg);
    return 0;
}

void loop(char *const ar)
{
    if (compare(msg, play) == 0)
    {
        mciSendStringA(reinterpret_cast<LPSTR>(initPath), nullptr, 0, nullptr);
        mciSendStringA("play BGM repeat", nullptr, 0, nullptr);
        while (true)
        {
            memset(msg, '\0', sizeof(*ar));
            cin >> msg;
            if (compare(ar, quit) == 0)
            {
                cout << "Bye!";
                mciSendStringA("close BGM", nullptr, 0, nullptr);
                exit(EXIT_SUCCESS);
            }
            else
            {
                loop(ar);
            }
        }
    }
    else if (compare(ar, quit) == 0)
    {
        cout << "Bye!";
        mciSendStringA("close BGM", nullptr, 0, nullptr);
        exit(EXIT_SUCCESS);
    }
    else if (compare(ar, pause) == 0)
    {
        cout << "Playing paused...Waiting for instructions \"resume\"\n:";
        mciSendStringA("stop BGM", nullptr, 0, nullptr);
        memset(msg, '\0', sizeof(*ar));
        cin >> msg;
        loop(msg);
    }
    else if (compare(ar, resume) == 0)
    {
        cout << "Play continues...";
        mciSendStringA("resume BGM", nullptr, 0, nullptr);
        memset(msg, '\0', sizeof(*ar));
        cin >> msg;
        loop(ar);
    }
    else if (compare(ar, cutsong) == 0)
    {
        cout << "Enter a new play file\n:";
        memset(inpath,'\0',sizeof(inpath));
        cin >> inpath;
        mciSendStringA("close BGM", nullptr, 0, nullptr);
        memset(initPath, '\0', sizeof(initPath));
        memset(msg, '\0', sizeof(*ar));
        for (int i = 0; i < sizeof(open)-1; i++)
        {
            initPath[i] = open[i];
        }
        strcat(initPath, inpath);
        strcat(initPath, aBgm);
        cout << "Retype \"play\" to play the new music file\n:";
        cin >> msg;
        loop(msg);
    }
    else
    {
        cout << "Not command parameter!" << endl << "Please try it again!\n:" << endl;
        memset(msg, '\0', sizeof(*ar));
        cin >> msg;
        loop(msg);
    }
}

int compare(const char *ar1,const char *ar2)
{
    for (int i = 0; i < sizeof(*ar2); i++)
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
