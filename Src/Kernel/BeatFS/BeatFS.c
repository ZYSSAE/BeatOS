#include "BeatFS.h"

FSNode FSRoot={"",0,0,0,0,NULL,NULL,NULL};

FSNode *FS_CreateNode(INT8 *Name,NodeDescriptor *Info,Session (*Open)(INT8 *Arg),FSError (*Close)(Session *Ses))
{
	FSNode *Node=(FSNode *)malloc(sizeof(FSNode));
	Node->Name=malloc(sizeof(Name));
	strcpy(Node->Name,Name);
	Node->Info=Info;
	Node->Open=Open;
	Node->Close=Close;
	Node->OpenCount=0;
	Node->Child=NULL;
	Node->Prev=NULL;
	Node->Next=NULL;
	return Node;
}

FSNode *FS_GetChild(FSNode *Father,INT8X *Name)
{
	if(Father==NULL)return &FSRoot;
	FSNode *Node=Father->Child;
	while(Node)
	{
		if(strcmp(Node->Name,Name)==0)return Node;
		Node=Node->Next;
	}
	return NULL;
}

FSError FS_CheckPath(INT8X *Path)
{
	if(*Path!='/')return FS_PathError;
	if(*(Path+strlen(Path)-1)!='/')return FS_PathError;
	return FS_NoError;
}

FSNode *FS_GetNearestNode(INT8X *Path,INT8 *Arg)
{
	INT8 *TempPath=malloc(sizeof(Path));
	INT8 *Lock=TempPath;
	INT8 *TempName;
	strcpy(TempPath,Path);
	FSNode *TempNode=FS_GetChild(NULL,strsep(&TempPath, "/"));
	while(strcmp(TempPath,"")!=0)
	{
		if(TempNode->Child==NULL)
		{
			strcpy(Arg,TempPath);
			free(Lock);
			return TempNode;
		}
		TempName=strsep(&TempPath, "/");
		if(FS_GetChild(TempNode,TempName))
			TempNode=FS_GetChild(TempNode,TempName);
		else
		{
			*(TempPath-1)='/';
			while(*(TempPath-1)!=0)TempPath--;
			strcpy(Arg,TempPath);
			free(Lock);
			return TempNode;
		}
	}
	free(Lock);
	return NULL;
}

FSError FS_Mount(INT8X *Path,Session (*Open)(INT8 *Arg),FSError (*Close)(Session *Ses))
{
	if(FS_CheckPath(Path)==FS_PathError)return FS_PathError;
	INT8 *Arg=malloc(sizeof(INT8)*100);
	FSNode *ParentNode=FS_GetNearestNode(Path,Arg);
	printf("%s %s\n",ParentNode->Name,Arg);
	INT8 *TempPath=Arg;
	if(ParentNode->Child)
	{
		for(ParentNode=ParentNode->Child;ParentNode->Next!=NULL;ParentNode=ParentNode->Next);
		ParentNode->Next=FS_CreateNode(strsep(&TempPath, "/"),NULL,NULL,NULL);
		ParentNode->Next->Prev=ParentNode;
		ParentNode=ParentNode->Next;
	}
	while(strcmp(TempPath,"")!=0)
	{
		ParentNode->Child=FS_CreateNode(strsep(&TempPath, "/"),NULL,NULL,NULL);
		ParentNode=ParentNode->Child;
	}
	ParentNode->Open=Open;
	ParentNode->Close=Close;
	free(Arg);
	return FS_NoError;
}

FSError FS_UnMount(INT8X *Path);
Session FS_Open(INT8X *Path);
FSError FS_Close(Session *Ses);
