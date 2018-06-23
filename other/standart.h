#include<Windows.h>
#include<string>
//=======================
//Отримати місцезнаходження програми
char* SvcInstall()
{
    TCHAR szPath[MAX_PATH];

    if( !GetModuleFileName( NULL, szPath, MAX_PATH ) )
    {
        return "error";
    }

    return szPath;
}

//Отримати місцезнаходження програми і задати папку як кореневу
std::string SetDIR()
{
		//получаим путь к програме
	std::string urlK = "";
	urlK += SvcInstall(); 
	//удаляем всё до слеша (название програмы)
	while(urlK.size() > 0) { bool br = 0;if(urlK[urlK.size()-1] == '/' || urlK[urlK.size()-1] == '\\'){br = 1;}
	urlK.erase(urlK.size()-1); if(br)break; }
	//устанавливаем путь к кааталогу с прорамой как основной
	SetCurrentDirectory(urlK.c_str());

    return urlK;
}