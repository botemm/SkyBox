#include<Windows.h>
#include<string>
//=======================
//�������� ��������������� ��������
char* SvcInstall()
{
    TCHAR szPath[MAX_PATH];

    if( !GetModuleFileName( NULL, szPath, MAX_PATH ) )
    {
        return "error";
    }

    return szPath;
}

//�������� ��������������� �������� � ������ ����� �� ��������
std::string SetDIR()
{
		//�������� ���� � ��������
	std::string urlK = "";
	urlK += SvcInstall(); 
	//������� �� �� ����� (�������� ��������)
	while(urlK.size() > 0) { bool br = 0;if(urlK[urlK.size()-1] == '/' || urlK[urlK.size()-1] == '\\'){br = 1;}
	urlK.erase(urlK.size()-1); if(br)break; }
	//������������� ���� � ��������� � �������� ��� ��������
	SetCurrentDirectory(urlK.c_str());

    return urlK;
}