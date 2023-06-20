#pragma once

typedef struct {
	void* data;
	int size;
	int capacityAndFlags;
} hkArray;

typedef struct {
	void* data;
	int size;
} SimpleArray;

typedef struct {
	int x;
	int y;
	int z;
	int w;
} Vector4;

typedef struct {
	Vector4 translation;
	Vector4	rotation;
	Vector4	scale;
} QsTransform;

typedef struct {
	void* vtable;
	unsigned short memSizeAndFlags;
	short referenceCount;
} hkReferencedObject;

typedef struct {
	int name;
	int annotation;
	int numAnnotations;
	int pad;
} hkaAnnotationTrack;

typedef struct {
	int time;
	int text;
	int pad[2];
} Annotation;

typedef struct {
	char name[16];
} AnnotationTrackName;

typedef struct {
	int pName;
	int lockTranslation;
	int pad;
	int pad1;
	char name[32];
} hkaBone;

typedef struct {
	int loc;
	int dst;
} arrayOffset;