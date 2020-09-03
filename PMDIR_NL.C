/* PMDir.C */

#define INCL_DOSERRORS
#define INCL_DOSFILEMGR
#define INCL_WINWORKPLACE

#include <os2.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
HOBJECT hObject;
UCHAR achDirName[CCHMAXPATH]={0},view[16]={0},object[CCHMAXPATH]={0};
ULONG cbDirPathLen=0,ulDriveMap=0,ulDriveNum=0;

cbDirPathLen=(ULONG)sizeof(achDirName);
if (DosQueryCurrentDir(ulDriveNum,achDirName,&cbDirPathLen)==NO_ERROR)
   {
   if (DosQueryCurrentDisk(&ulDriveNum,&ulDriveMap)==NO_ERROR)
      {
      printf("\nPMDIR [[B]oomstructuur | [D]etails | [P]ictogrammen | [I]nstellingen]\n");
      sprintf(object,"%c:\\%s",'A'+ulDriveNum-1,achDirName,argc);
      printf("Map-> %s\n",object);
   
      strcpy(view,"OPEN=\0");
      if (argc==1)      
         strcat(view,"DEFAULT\0");
      else   
         {
         switch(argv[1][0])
            {
            case 'P':
            case 'p':
               strcat(view,"ICON\0");
               break;
            case 'D':
            case 'd':
               strcat(view,"DETAILS\0");
               break;
            case 'B':
            case 'b':
               strcat(view,"TREE\0");
               break;
            case 'I':
            case 'i':
               strcat(view,"SETTINGS\0");
               break;
            default:            
               strcat(view,"DEFAULT\0");
            }
         }
      if (NULLHANDLE!=(hObject=WinQueryObject(object)))
         if (WinSetObjectData(hObject,view)==TRUE) /* open object */
            WinSetObjectData(hObject,view); /* move object to foreground */
      }
   }

return 0;
}

