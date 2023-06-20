// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <comdef.h>

#include <Common/Base/hkBase.h>
#include <Common/Base/KeyCode.h>
#include <Common/Serialize/hkSerialize.h>
#include <Common/Serialize/Util/hkNativePackfileUtils.h>
#include <Common/Serialize/Util/hkStructureLayout.h>
#include <Common/Serialize/Util/hkRootLevelContainer.h>

#include <Common/Base/System/hkBaseSystem.h>
#include <Common/Base/System/Io/IStream/hkIStream.h>
#include <Common/Base/System/Io/Reader/hkStreamReader.h>
#include <Common/Base/System/Error/hkDefaultError.h>
#include <Common/Base/Memory/System/Util/hkMemoryInitUtil.h>
#include <Common/Base/Memory/System/hkMemorySystem.h>
#include <Common/Base/Memory/Allocator/Malloc/hkMallocAllocator.h>
#include <Common/Base/Monitor/hkMonitorStream.h>
#include <Common/Base/Reflection/hkClass.h>

#include <Animation/Animation/hkaAnimationContainer.h>
#include <Animation/Animation/Animation/hkaAnimation.h>
#include <Animation/Animation/Animation/SplineCompressed/hkaSplineCompressedAnimation.h>
#include <Animation/Animation/Animation/Interleaved/hkaInterleavedUncompressedAnimation.h>
#include <Animation/Animation/Animation/Deprecated/WaveletCompressed/hkaWaveletCompressedAnimation.h>
#include <Animation/Animation/Animation/Deprecated/DeltaCompressed/hkaDeltaCompressedAnimation.h>
#include <Animation/Animation/Motion/Default/hkaDefaultAnimatedReferenceFrame.h>

void decompressAnims(hkRootLevelContainer*);


//#include <Common/Base/Config/hkProductFeatures.cxx>
// TODO: reference additional headers your program requires here
