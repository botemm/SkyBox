//===================================================================================
//===================================================================================
//Автор: Писанка Юрій Валентинович
//Рік 2017
//Вироблено Християнином
//Опис: Класс камера, призначений для створення віртуальних камер для спрошення роботи з відображенням сцени і переміщень по ній
//
//Camera()  //Викликається для застосування камери викликається після фушкцій glViewport i  gluPerspective. Фунція застосовує параметри зміщення і повороту
//CameraR() //Окремо застосовує тільки повороти каери без зміщень
//CameraR(float X,float Y,float Z) //Теж саме що CameraR() тальки як аргументи задаються свої повороти Дані збервгаються як основні
//CameraT() //Окремо застосовує тільки зміщення каери без поворотів
//CameraT(float X,float Y,float Z) //Теж саме що CameraT() Тільки як аргументи задаються свої координати Дані збервгаються як основні
//CameraUP_Down(float ZN) //Рух камери вперед і назад залежно від того чи аргумент + чи - Сам аргумент задає швидкість Камера прекріплена до землі Вісі (x, z)
//CameraM::CameraUP_Down_VILNA  //Теж саме що CameraUP_Down(float ZN) але камера не прикріплена до чогось вільна. (Камера рухається туди куди дивиться)
//CameraRXN(float X_ZM) //Поворот по вісі X
//CameraRYN(float Y_ZM) //Поворот по вісі Y
//CameraRZN(float Z_ZM) //Поворот по вісі Z

//Прямий доступ до змінних
//	float RX,RY,RZ;  //Повороти камери
//	float TX,TY,TZ;  //Позиція камери

#pragma once
#include<GL\GL.H>
//*#include<AL\al.h>
#include<math.h>
class CameraM
{

public:

	float RX,RY,RZ;
	float TX,TY,TZ;
	float Speed;


	CameraM() //Конструктор
	{
		RX = 0;
		RY = 0;
		RZ = 0;
		TX = 0;
		TY = 1;
		TZ = 0;
	}

	void Camera()
	{
		CameraR();
		CameraT();
		Speed = 0;
	} //Примінити камкру Все

	
	void CameraR()
	{
		glRotatef(RX,1,0,0);
		glRotatef(RZ,0,0,1);
		glRotatef(RY,0,1,0);

	} //задіяти кути
	
	void CameraT(float X,float Y,float Z)
	{
		TX = X;
		TY = Y;
		TZ = Z;
		CameraT();	
	} //Задати і примінити Зміщенння


	void CameraM::CameraR(float X,float Y,float Z)
	{
		RX = X;
		RY = Y;
		RZ = Z;
		CameraR();
	} //Примінити кути вказавши їх


	void CameraT()
	{
		//*ALfloat ListenerPos[] = {TX,TY,TZ};
		//*alListenerfv(AL_POSITION,    ListenerPos);
		glTranslatef(-TX,-TY,-TZ);



	//*  ALfloat ListenerOri[] = { TX, TY, TZ,  TX - sin(6.28273/360*RY)*5, TY + sin(6.28273/360*RX)*5, TZ + cos(6.28273/360*RY)*5 };
      //*alListenerfv(AL_ORIENTATION, ListenerOri);

	} //Примінити Зміщенння
	
	void CameraM::CameraUP_Down(float ZN) //–ух вперед назад залежно в≥д значенн¤
	{
		ZN*=-1;
		TX -= (sin(6.28273/360*RY) * ZN) * Speed; 
		TZ += (cos(6.28273/360*RY) * ZN) * Speed;
		//TY += sin(6.28273/360*RX) * ZN;
	} //Рух вперед назад залежно від значення

	void CameraM::CameraUP_Down_VILNA(float ZN) //–ух вперед назад вверх залежно в≥д значенн¤
	{
		ZN*=-1;
		TX -= (sin(6.28273/360*RY) * ZN) * Speed; 
		TZ += (cos(6.28273/360*RY) * ZN) * Speed;
		TY += (sin(6.28273/360*RX) * ZN) * Speed;
	} //Рух вперед назад вверх залежно від значення
	

	//Повертають змінене значення
	 float CameraM::CameraRYN(float Y_ZM) //ѕовертанн¤ камери по Y
	{
		RY+=Y_ZM * Speed;
		return RY;
	}//Повертання камери по Y

	float CameraM::CameraRXN(float X_ZM) //ѕовертанн¤ камери по X
	{
		RX+=X_ZM * Speed;
		return RX;
	} //Повертання камери по X

	float CameraM::CameraRZN(float Z_ZM) //ѕовертанн¤ камери по Z
	{
		RZ+=Z_ZM * Speed;
		return RZ;
	} //Повертання камери по Z


	~CameraM() //Деструктор
	{
	}
};







class fps_us
{
private:
	float fps_tt;
	float fps_t;
	float Temps_fps;

public:
	float fps;
	float deltaTime;
	
	fps_us()
	{
	fps = 0;
	fps_tt = 0;
	fps_t = 0;
	Temps_fps = 0;
	}


	int fps_v(int T)
	{
		deltaTime = (T-Temps_fps);
		Temps_fps = T;

		if(fps_t>=1000/4)
		{
			fps = fps_tt*4;
			fps_t = 0;
			fps_tt = 0;

			
		}
		else
		{
			fps_t+=deltaTime;
			fps_tt++;
		}

		return fps;

	}

};

