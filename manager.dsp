# Microsoft Developer Studio Project File - Name="manager" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=manager - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "manager.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "manager.mak" CFG="manager - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "manager - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "manager - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "manager - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "manager - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "manager - Win32 Release"
# Name "manager - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AboutPayDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AboutPaySet.cpp
# End Source File
# Begin Source File

SOURCE=.\AddrBookDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddrbookSet.cpp
# End Source File
# Begin Source File

SOURCE=.\AddSysInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AttDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AttendanceSet.cpp
# End Source File
# Begin Source File

SOURCE=.\AttErrand.cpp
# End Source File
# Begin Source File

SOURCE=.\AttLeave.cpp
# End Source File
# Begin Source File

SOURCE=.\AttOvertime.cpp
# End Source File
# Begin Source File

SOURCE=.\AttStatDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AttStatSet.cpp
# End Source File
# Begin Source File

SOURCE=.\AttWork.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BookInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BrowseDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DeptDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DeptSet.cpp
# End Source File
# Begin Source File

SOURCE=.\DutyDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DutySet.cpp
# End Source File
# Begin Source File

SOURCE=.\EducationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EducationSet.cpp
# End Source File
# Begin Source File

SOURCE=.\ErrandSet.cpp
# End Source File
# Begin Source File

SOURCE=.\FamilyDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FamilySet.cpp
# End Source File
# Begin Source File

SOURCE=.\FolkDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FolkSet.cpp
# End Source File
# Begin Source File

SOURCE=.\HistoryDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HistorySet.cpp
# End Source File
# Begin Source File

SOURCE=.\HonorDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HonorSet.cpp
# End Source File
# Begin Source File

SOURCE=.\LeaveSet.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\manager.cpp
# End Source File
# Begin Source File

SOURCE=.\manager.rc
# End Source File
# Begin Source File

SOURCE=.\managerDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\managerView.cpp
# End Source File
# Begin Source File

SOURCE=.\NotePadDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NotePadSet.cpp
# End Source File
# Begin Source File

SOURCE=.\OvertimeSet.cpp
# End Source File
# Begin Source File

SOURCE=.\PassWord.cpp
# End Source File
# Begin Source File

SOURCE=.\PersonSet.cpp
# End Source File
# Begin Source File

SOURCE=.\PoliticalDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PoliticalSet.cpp
# End Source File
# Begin Source File

SOURCE=.\QualificationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\QualificationSet.cpp
# End Source File
# Begin Source File

SOURCE=.\RecordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TabSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\TechnicalDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TechnicalSet.cpp
# End Source File
# Begin Source File

SOURCE=.\TrainDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TrainSet.cpp
# End Source File
# Begin Source File

SOURCE=.\UserDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WorkerStatusDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WorkerStatusSet.cpp
# End Source File
# Begin Source File

SOURCE=.\WorkplanDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AboutPayDlg.h
# End Source File
# Begin Source File

SOURCE=.\AboutPaySet.h
# End Source File
# Begin Source File

SOURCE=.\AddrBookDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddrbookSet.h
# End Source File
# Begin Source File

SOURCE=.\AddSysInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\AttDlg.h
# End Source File
# Begin Source File

SOURCE=.\AttendanceSet.h
# End Source File
# Begin Source File

SOURCE=.\AttErrand.h
# End Source File
# Begin Source File

SOURCE=.\AttLeave.h
# End Source File
# Begin Source File

SOURCE=.\AttOvertime.h
# End Source File
# Begin Source File

SOURCE=.\AttStatDlg.h
# End Source File
# Begin Source File

SOURCE=.\AttStatSet.h
# End Source File
# Begin Source File

SOURCE=.\AttWork.h
# End Source File
# Begin Source File

SOURCE=.\BaseInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\BookInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\BrowseDlg.h
# End Source File
# Begin Source File

SOURCE=.\DeptDlg.h
# End Source File
# Begin Source File

SOURCE=.\DeptSet.h
# End Source File
# Begin Source File

SOURCE=.\DutyDlg.h
# End Source File
# Begin Source File

SOURCE=.\DutySet.h
# End Source File
# Begin Source File

SOURCE=.\EducationDlg.h
# End Source File
# Begin Source File

SOURCE=.\EducationSet.h
# End Source File
# Begin Source File

SOURCE=.\ErrandSet.h
# End Source File
# Begin Source File

SOURCE=.\FamilyDlg.h
# End Source File
# Begin Source File

SOURCE=.\FamilySet.h
# End Source File
# Begin Source File

SOURCE=.\FolkDlg.h
# End Source File
# Begin Source File

SOURCE=.\FolkSet.h
# End Source File
# Begin Source File

SOURCE=.\HistoryDlg.h
# End Source File
# Begin Source File

SOURCE=.\HistorySet.h
# End Source File
# Begin Source File

SOURCE=.\HonorDlg.h
# End Source File
# Begin Source File

SOURCE=.\HonorSet.h
# End Source File
# Begin Source File

SOURCE=.\LeaveSet.h
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\manager.h
# End Source File
# Begin Source File

SOURCE=.\managerDoc.h
# End Source File
# Begin Source File

SOURCE=.\managerView.h
# End Source File
# Begin Source File

SOURCE=.\NotePadDlg.h
# End Source File
# Begin Source File

SOURCE=.\NotePadSet.h
# End Source File
# Begin Source File

SOURCE=.\OvertimeSet.h
# End Source File
# Begin Source File

SOURCE=.\PassWord.h
# End Source File
# Begin Source File

SOURCE=.\PersonSet.h
# End Source File
# Begin Source File

SOURCE=.\PoliticalDlg.h
# End Source File
# Begin Source File

SOURCE=.\PoliticalSet.h
# End Source File
# Begin Source File

SOURCE=.\QualificationDlg.h
# End Source File
# Begin Source File

SOURCE=.\QualificationSet.h
# End Source File
# Begin Source File

SOURCE=.\RecordDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SearchDlg.h
# End Source File
# Begin Source File

SOURCE=.\Skins\SkinPlusPlus.h
# End Source File
# Begin Source File

SOURCE=.\StatDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TabSheet.h
# End Source File
# Begin Source File

SOURCE=.\TechnicalDlg.h
# End Source File
# Begin Source File

SOURCE=.\TechnicalSet.h
# End Source File
# Begin Source File

SOURCE=.\TrainDlg.h
# End Source File
# Begin Source File

SOURCE=.\TrainSet.h
# End Source File
# Begin Source File

SOURCE=.\UserDlg.h
# End Source File
# Begin Source File

SOURCE=.\WorkerStatusDlg.h
# End Source File
# Begin Source File

SOURCE=.\WorkerStatusSet.h
# End Source File
# Begin Source File

SOURCE=.\WorkplanDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\0003.BMP
# End Source File
# Begin Source File

SOURCE=.\res\bg.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ICON3.ico
# End Source File
# Begin Source File

SOURCE=.\res\manager.ico
# End Source File
# Begin Source File

SOURCE=.\res\manager.rc2
# End Source File
# Begin Source File

SOURCE=.\res\managerDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Tool.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbars.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\Skins\SkinPlusPlusDLL.lib
# End Source File
# End Target
# End Project
