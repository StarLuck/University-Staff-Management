// AttStatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "AttStatDlg.h"
#include "PersonSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAttStatDlg dialog


CAttStatDlg::CAttStatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAttStatDlg::IDD, pParent)
{
	CTime End_t=CTime::GetCurrentTime(); // ��ǰʱ��
	CTimeSpan tp(30,0,0,0); // ʱ����Ϊ30��
	//{{AFX_DATA_INIT(CAttStatDlg)
	m_strTime = End_t.Format("%Y-%m");
	m_STime = End_t-tp;
	m_ETime = End_t;
	m_bSeekbytime = FALSE;
	m_bSeekbyperson = FALSE;
	m_strSeektime = _T("");
	m_strPersonID = _T("");
	m_strPersonName = _T("");
	//}}AFX_DATA_INIT
}


void CAttStatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttStatDlg)
	DDX_Control(pDX, IDC_STAT_LIST, m_cList);
	DDX_Text(pDX, IDC_STAT_EDT_TIME, m_strTime);
	DDX_DateTimeCtrl(pDX, IDC_STAT_DATETIMEPICKER_STARTTIME, m_STime);
	DDX_DateTimeCtrl(pDX, IDC_STAT_DATETIMEPICKER_ENDTIME, m_ETime);
	DDX_Check(pDX, IDC_STAT_CHK_SEEKBYTIME, m_bSeekbytime);
	DDX_Check(pDX, IDC_STAT_CHK_SEEKBYPERSON, m_bSeekbyperson);
	DDX_Text(pDX, IDC_STAT_EDT_SEEKTIME, m_strSeektime);
	DDX_Text(pDX, IDC_STAT_EDT_SEEKPERSONID, m_strPersonID);
	DDX_Text(pDX, IDC_STAT_EDT_SEEKPERSONNAME, m_strPersonName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAttStatDlg, CDialog)
	//{{AFX_MSG_MAP(CAttStatDlg)
	ON_EN_CHANGE(IDC_STAT_EDT_SEEKPERSONID, OnChangeStatEdtSeekpersonid)
	ON_BN_CLICKED(IDC_STAT_BTN_SEEK, OnStatBtnSeek)
	ON_BN_CLICKED(IDC_STAT_BTN_STAT, OnStatBtnStat)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAttStatDlg message handlers

void CAttStatDlg::OnChangeStatEdtSeekpersonid() 
{
	UpdateData(); 

	CPersonSet rs; 
	rs.m_strFilter = "ID='" + m_strPersonID + "'"; 
	rs.Open(); 
	if(rs.GetRecordCount()==1) 
	{
		m_strPersonName=rs.m_name; 
	}
	else m_strPersonName.Empty(); 
	rs.Close(); 
	UpdateData(FALSE); 
}

void CAttStatDlg::OnStatBtnSeek() 
{
	CString strFilter; 
	CAttStatSet rs; 

	UpdateData(); 
	// �жϸ���Ա���Ź���
	if(m_bSeekbyperson) strFilter="PERSON='" + m_strPersonID + "'";
	// �жϸ������¹���
	if(m_bSeekbytime)
	{
		if(!strFilter.IsEmpty())  
			strFilter += " and ";
	
		strFilter += "YEAR_MONTH='" + m_strSeektime + "'";
	}
	// ���ù�������
	if(!strFilter.IsEmpty()) 
	{
		rs.m_strFilter=strFilter; 
	}
	// �����б��
	UpdateList(rs); 
}

BOOL CAttStatDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// �����б�
	int nWidth=100;
	m_cList.InsertColumn(0, "��¼���", LVCFMT_LEFT, 80);
	m_cList.InsertColumn(1, "Ա����", LVCFMT_LEFT, 50);
	m_cList.InsertColumn(2, "����", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(3, "��������ʱ��(Сʱ)", LVCFMT_LEFT, nWidth+40);
	m_cList.InsertColumn(4, "�Ӱ�ʱ��(Сʱ)", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(5, "���ʱ��(����)", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(6, "����ʱ��(����)", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(7, "�ٵ�����", LVCFMT_LEFT, nWidth-30);
	m_cList.InsertColumn(8, "���˴���", LVCFMT_LEFT, nWidth-30);
	m_cList.InsertColumn(9, "��������", LVCFMT_LEFT, nWidth-30);
	m_cList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	// �����б�
	CAttStatSet rs; 
	UpdateList(rs); 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAttStatDlg::UpdateList(CAttStatSet& rs)
{
	int i=0;
	CString str;
	// ����б������
	m_cList.DeleteAllItems(); 
	//��ʾȫ������
	rs.Open(); 
	while(!rs.IsEOF()) 
	{
		m_cList.InsertItem(i, ""); 
		str.Format("%d", rs.m_ID); 
		m_cList.SetItemText(i, 0, str);
		m_cList.SetItemText(i, 1, rs.m_PERSON);
		m_cList.SetItemText(i, 2, rs.m_YEAR_MONTH);
		str.Format("%d", rs.m_WORK_HOUR);
		m_cList.SetItemText(i, 3, str);
		str.Format("%d", rs.m_OVER_HOUR);
		m_cList.SetItemText(i, 4, str);
		str.Format("%d", rs.m_LEAVE_HDAY);
		m_cList.SetItemText(i, 5, str);
		str.Format("%d", rs.m_ERRAND_HDAY);
		m_cList.SetItemText(i, 6, str);
		str.Format("%d", rs.m_LATE_TIMES);
		m_cList.SetItemText(i, 7, str);
		str.Format("%d", rs.m_EARLY_TIMES);
		m_cList.SetItemText(i, 8, str);
		str.Format("%d", rs.m_ABSENT_TIMES);
		m_cList.SetItemText(i, 9, str);
		rs.MoveNext(); 
		i++;
	}
	rs.Close(); 
}

void CAttStatDlg::OnStatBtnStat() 
{
	CDatabase db;
	db.Open(_T("Manager"));
	CRecordset rs_attend(&db); 
	CRecordset rs_leave(&db);  
	CRecordset rs_errand(&db);  
	CTimeSpan tp_1(1,0,0,0); // ����һ��1���CTimeSpan
	CTimeSpan tp_02(0,2,0,0); // ����һ��2Сʱ��CTimeSpan
	CTimeSpan TimeSpan[4]; // �������°�ʱ��
	int nHours[2]; // ���������繤��ʱ��
	CString strSTime,strETime; // ����ʼĩʱ��
	CTime TimeStamp, LateTime, EarlyTime,WorkStart,WorkEnd; // �����м��ж�ʱ��
	int nWorkHour,nOverHour,nLeaveHDay,nErrandHDay; // ����ʱ��������
	BOOL bLate,bEarly,bAbsent,bLeave,bErrand; // �����жϽ��
	int nLateTimes,nEarlyTimes,nAbsentTimes; // �������
	CString cstr[4]; // �ݴ���ʼʱ��
	char str[4][9]; // �ݴ���ʼʱ��
	int i,j,n; // ����ѭ���ͼ���
	CString strTmp,strTmp1,strTmp2; // ��ʱ����
	// ��ʱ����,��,��,��,ʱ,��,��
	int nHour,nMinute,nSecond;
	CString strFileName=".\\workplan.ini"; // INI�ļ���

	UpdateData(); // ��������
	// ��ȡINI�ļ�
	GetPrivateProfileString("WorkPlan", "Time1", "08:00:00", str[0], 9, strFileName);
	GetPrivateProfileString("WorkPlan", "Time2", "12:00:00", str[1], 9, strFileName);
	GetPrivateProfileString("WorkPlan", "Time3", "14:00:00", str[2], 9, strFileName);
	GetPrivateProfileString("WorkPlan", "Time4", "18:00:00", str[3], 9, strFileName);
	for(i=0; i<4; i++) cstr[i]=str[i];

	// �����ĸ�ʱ������������ʼ��ΪINI�ļ��е�ֵ
	CTimeSpan *pTS;
	for(i=0; i<4; i++)
	{
		sscanf(cstr[i].Left(2), "%d", &nHour);		// �õ�ʱ
		sscanf(cstr[i].Mid(3,2), "%d", &nMinute);	// �õ���
		sscanf(cstr[i].Mid(6,2), "%d", &nSecond);	// �õ���
		// ����һ��ʱ��������
		pTS=new CTimeSpan(0,nHour,nMinute,nSecond);
		TimeSpan[i]=*pTS; // ��ֵ
		delete pTS;
	}
	nHours[0]=(TimeSpan[1]-TimeSpan[0]).GetTotalHours(); // �������繤��ʱ��
	if((TimeSpan[1]-TimeSpan[0]).GetMinutes()>30) nHours[0]++; // ��������
	nHours[1]=(TimeSpan[3]-TimeSpan[2]).GetTotalHours(); // �������繤��ʱ��
	if((TimeSpan[3]-TimeSpan[2]).GetMinutes()>30) nHours[1]++; // ��������
	// ת��ͳ�ƿ�ʼʱ��
	strSTime=m_STime.Format("%Y-%m-%d");
	// ת��ͳ�ƽ���ʱ�䣬��������1
	strETime=(m_ETime+tp_1).Format("%Y-%m-%d");
	// ��ȡԱ���б�
	CPersonSet rs_person; // ����Ա����
	rs_person.Open(); // ��Ա����
	n=rs_person.GetRecordCount(); // ��¼Ա������
	i=0; // ��ʼ���Ѵ���Ա������

	while(!rs_person.IsEOF()) // ���ζ�ÿ��Ա������ͳ��
	{
		//��ȡ���ڼ�¼
		// ִ�в�ѯ
		CString stringStime=strSTime;
		CString stringEtime=strETime;

		rs_attend.Open(CRecordset::forwardOnly,
			"select IN_OUT,IO_TIME from ATTENDANCE\
			where PERSON='" + rs_person.m_ID
			+ "' and IO_TIME>" + stringStime
			+ " and IO_TIME<" +stringEtime
			+ " order by IO_TIME");

		strTmp1.Empty(); // ���strTmp1
		// ��ʼ��
		nWorkHour=nOverHour=0;
		nLeaveHDay=nErrandHDay=0;
		nLateTimes=nEarlyTimes=nAbsentTimes=0;
		TimeStamp=m_STime; // ��ʼ��ʱ���Ϊͳ�ƿ�ʼʱ��
		while(TimeStamp < m_ETime+tp_02) // �ж��Ƿ񳬳�ͳ�ƽ���ʱ��
		{
			if(TimeStamp.GetDayOfWeek()!=1 &&
			   TimeStamp.GetDayOfWeek()!=7) // �ж��Ƿ�����
			{
				for(j=0;j<=1;j++) // �������
				{
					rs_attend.Close();
					LateTime=TimeStamp+TimeSpan[2*j]; // ���óٵ�ʱ��
					EarlyTime=TimeStamp+TimeSpan[2*j+1]; // ��������ʱ��
					// �ж��Ƿ����

					rs_leave.Open(CRecordset::forwardOnly,
						"select ID from LEAVE where\
						PERSON='" + rs_person.m_ID
						+ "' and START_TIME<"
						+ LateTime.Format("%Y-%m-%d")
						+ " and END_TIME>"
						+ EarlyTime.Format("%Y-%m-%d")
						+ "");
					bLeave=(rs_leave.GetRecordCount()>0);	// �ж��Ƿ�����ټ�¼
					rs_leave.Close(); // �رռ�¼��
					// �ж��Ƿ����
					rs_errand.Open(CRecordset::forwardOnly,
						"select ID from ERRAND where\
						PERSON='" + rs_person.m_ID
						+ "' and START_TIME<"
						+ LateTime.Format("%Y-%m-%d")
						+ " and END_TIME>"
						+ EarlyTime.Format("%Y-%m-%d")
						+ "");
					bErrand=(rs_errand.GetRecordCount()>0); // �ж��Ƿ��г����¼
					rs_errand.Close(); // �رռ�¼��
					rs_attend.Open(CRecordset::forwardOnly,
			"select IN_OUT,IO_TIME from ATTENDANCE\
			where PERSON='" + rs_person.m_ID
			+ "' and IO_TIME>" + stringStime
			+ " and IO_TIME<" +stringEtime
			+ " order by IO_TIME");
					if(bLeave) // �������ټ�¼
						nLeaveHDay++; // ��ټ�¼��1
					else if(bErrand) // ����г����¼
					{
						nErrandHDay++; // ���������1
						nWorkHour+=nHours[j]; // ���������ۼӹ���ʱ��
					}
					else // �����ϰ�
					{
						WorkStart=LateTime; // ���ù�����ʼʱ��
						WorkEnd=EarlyTime; // ���ù�������ʱ��
						bLate=TRUE; // ��ʼ���ٵ��ж�
						bAbsent=FALSE; // ��ʼ�������ж�
						// �ж��Ƿ�ٵ�
						if(!rs_attend.IsEOF() && // ��¼������
							strTmp1.IsEmpty()) // ��,��һ��GetFieldValue
							rs_attend.GetFieldValue("IO_TIME",strTmp1); // �õ�IO_TIME
						while(!rs_attend.IsEOF()
							&& StrToTime(strTmp1)<=LateTime)
						{// ����ʱ��˳���ж��Ƿ�ٵ�
							// �õ�IN_OUT
							rs_attend.GetFieldValue("IN_OUT",strTmp2);
							bLate=(strTmp2=="O"); // �ж��ϰ�ʱ��ǰ�Ƿ񱨵�
							rs_attend.MoveNext(); // ������һ�����ڼ�¼
							// �õ�IO_TIME
							if(!rs_attend.IsEOF())
								rs_attend.GetFieldValue("IO_TIME",strTmp1);
						}
						// �ж��Ƿ����
						if(bLate) // �ж��Ƿ�ٵ�
						{
							if(!rs_attend.IsEOF() && StrToTime(strTmp1)<EarlyTime)
								WorkStart=StrToTime(strTmp1); // ��¼�ٵ�ʱ��
							else bAbsent=TRUE; // ����°�ǰ��δ������Ϊ����
						}
						bEarly=FALSE;
						// �ж��Ƿ�����
						while(!rs_attend.IsEOF() && StrToTime(strTmp1)<EarlyTime)
						{
							// �õ�IN_OUT
							rs_attend.GetFieldValue("IN_OUT",strTmp2);
							bEarly=(strTmp2=="O"); // �ж��Ƿ�������
							if(bEarly)
							{
								// ������ʱ���¼Ϊ��������ʱ��
								WorkEnd=StrToTime(strTmp1);
							}
							else WorkEnd=EarlyTime; // ���°�ʱ���¼Ϊ��������ʱ��
							rs_attend.MoveNext(); // ������һ�����ڼ�¼
							// �õ�IO_TIME
							if(!rs_attend.IsEOF())
								rs_attend.GetFieldValue("IO_TIME",strTmp1);
						}
						// ������������ӿ���������¼
						if(bAbsent) nAbsentTimes++;
						else
						{
							// ����ٵ������ӳٵ�������¼
							if(bLate) nLateTimes++;
							// ������ˣ��������˴�����¼
							if(bEarly) nEarlyTimes++;
							// ����ʵ�ʹ���ʱ��
							nWorkHour+=(WorkEnd-WorkStart).GetTotalHours();
							if((WorkEnd-WorkStart).GetMinutes()>30)
								nWorkHour++; // ��������
						}
					}
				} // End of �������
			} // End of �Ƿ�����
			TimeStamp+=tp_1; // �ƽ�һ��
		} // End of TimeStamp < m_ETime+tp_02
		rs_attend.Close(); // �ر�Q_attend��¼��
		// ͳ�ƼӰ�ʱ��
		CRecordset rs_overtime(&db); // ����Q_overtime��¼��
		rs_overtime.Open(CRecordset::forwardOnly,
			"select sum(WORK_HOURS) as SUM from OVERTIME\
			where PERSON='" + rs_person.m_ID
			+ "' and WORK_DATE>"
			+ m_STime.Format("%Y-%m-%d")
			+ " and WORK_DATE<"
			+ m_ETime.Format("%Y-%m-%d")
			+ "");
		if(rs_overtime.GetRecordCount()>0) // �м�¼
		{
			// ��ȡ�Ӱ�ʱ��
			rs_overtime.GetFieldValue("SUM",strTmp);
			sscanf(strTmp,"%d",&nOverHour);
		}
		else nOverHour=0; // �޼�¼
		rs_overtime.Close();
		// �ж��Ƿ����и��¿��ڼ�¼
		CAttStatSet rs_stat; // ����ͳ�����ݱ�
		// ���ù��˴�
		rs_stat.m_strFilter="PERSON='" + rs_person.m_ID
			+ "' and YEAR_MONTH='" + m_strTime + "'";
		rs_stat.Open(); // �����ݱ�
		if(rs_stat.GetRecordCount()==0) // �ж��Ƿ��и��·ݿ��ڼ�¼
		{

			// ׷��ͳ�Ƽ�¼
			rs_stat.AddNew();

			rs_stat.m_YEAR_MONTH=m_strTime;
			rs_stat.m_PERSON=rs_person.m_ID;
			rs_stat.m_WORK_HOUR=nWorkHour;
			rs_stat.m_OVER_HOUR=nOverHour;
			rs_stat.m_LEAVE_HDAY=nLeaveHDay;
			rs_stat.m_ERRAND_HDAY=nErrandHDay;
			rs_stat.m_LATE_TIMES=nLateTimes;
			rs_stat.m_EARLY_TIMES=nEarlyTimes;
			rs_stat.m_ABSENT_TIMES=nAbsentTimes;
			rs_stat.Update(); // �ύ�޸�
		}
		else
		{
			// ��¼�Ѵ����޸�����
			rs_stat.Edit();
			rs_stat.m_WORK_HOUR=nWorkHour;
			rs_stat.m_OVER_HOUR=nOverHour;
			rs_stat.m_LEAVE_HDAY=nLeaveHDay;
			rs_stat.m_ERRAND_HDAY=nErrandHDay;
			rs_stat.m_LATE_TIMES=nLateTimes;
			rs_stat.m_EARLY_TIMES=nEarlyTimes;
			rs_stat.m_ABSENT_TIMES=nAbsentTimes;
			rs_stat.Update(); // �ύ�޸�
		}
		rs_stat.Close(); // �ر����ݱ�
		i++; // ��ͳ��Ա������1

		rs_person.MoveNext(); // ������һ��Ա����¼
	}
	rs_person.Close(); // �ر�Ա����
	CAttStatSet rs_stat; // ����ͳ�����ݱ�
	UpdateList(rs_stat); // �����б��
}
// ��ʱ�䴮ת��ΪCTime�ͱ���
CTime CAttStatDlg::StrToTime(CString str)
{// ʱ�䴮��ʽ "%Y-%m-%d %H:%M:%S",��"1999-01-01 11:11:11"
	int nYear,nMonth,nDay,nHour,nMinute,nSecond;
	sscanf(str.Left(4), "%d", &nYear); // �õ���
	sscanf(str.Mid(5,2), "%d", &nMonth); // �õ���
	sscanf(str.Mid(8,2), "%d", &nDay); // �õ���
	sscanf(str.Mid(11,2), "%d", &nHour); // �õ�ʱ
	sscanf(str.Mid(14,2), "%d", &nMinute); // �õ���
	sscanf(str.Mid(17,2), "%d", &nSecond); // �õ���
	// ����CTime����
	CTime result(nYear,nMonth,nDay,nHour,nMinute,nSecond);
	return result;
}
