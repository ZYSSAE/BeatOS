/*
 * BeatFS.h
 *
 * INUTE 2014
 *
 * BeatFS is a Virtual Filesystem for BeatOS
 */

#ifndef BEATFS_H_
#define BEATFS_H_

#include "BeatOS_PublicInclude.h"

typedef enum FSError{
	FS_NoError,
	FS_PathError,
	FS_UnknownError
}FSError;

typedef struct Session{
	INT8 *PWD;
	INT8 *Name;
	INT8 *Arg;
	UINT32 (*Read)(struct Session *Ses);
	void (*Write)(struct Session *Ses,UINT32 Data);
	FSError (*IOCTL)(struct Session *Ses,UINT32 Operation,void *Arg);
}Session;

typedef struct NodeDescriptor{
	UINT16 CreateTime;
	UINT16 Owner;
	UINT8 Permission;
	UINT8 *Description;
}NodeDescriptor;

typedef struct FSNode{
	INT8 *Name;
	NodeDescriptor *Info;
	Session (*Open)(INT8 *Arg);
	FSError (*Close)(Session *Ses);
	UINT16 OpenCount;
	struct FSNode *Child;
	struct FSNode *Prev;
	struct FSNode *Next;
}FSNode;

FSError FS_Mount(INT8X *Path,Session (*Open)(INT8 *Arg),FSError (*Close)(Session *Ses));
FSError FS_UnMount(INT8X *Path);
Session FS_Open(INT8X *Path);
FSError FS_Close(Session *Ses);

#endif /* BEATFS_H_ */
