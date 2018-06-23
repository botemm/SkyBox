class SkyBox
{
public:

	//Керування зміщення текстурних координат
	float TXtx;
	float TYtx;

	//Зжимаємо текстуру або ростягування
	float TXsca;
	float TYsca;

	//Координатне стиснення і розтягування сфери
	float MeshSX;
	float MeshSY;
	float MeshSZ;

	//Зміщеня об'єкта
	float MeshTX;
	float MeshTY;
	float MeshTZ;


	//pi
	float PI;


	//Текстура
	GLuint Textura;



	SkyBox()
	{
			PI = 3.14159265358979;

			TXtx = 0;
			TYtx = 0;

			TXsca = 1;
			TYsca = 1;

			
			MeshSX= 550;
			MeshSY= 500;
			MeshSZ =550;
			/*MeshSX= 1;
			MeshSY= 1;
			MeshSZ =1;*/

			MeshTX = 0;
			MeshTY = 0;
			MeshTZ = 0;
	}



	void draw()
	{
		//TXtx  = sin(TempI*15);
//================================/ Темчасові змінні /=========
	float c = 0;
	float Pi2 = PI*2;
	c = 0;
	float c2 = -(Pi2/2)/2;
	float dilt = (1 * Pi2) ;//*sin(TempI);
	float dilt2 = 3.14;

	float Radius1 = 1;
	float Radius2 = 1;

	float r;
	int t;
	r = 0;
	t = 0;
//================================/ Темчасові змінні /=========


//glRotatef(90,0,1,0);
	glBindTexture(GL_TEXTURE_2D,Textura);
glBegin(GL_TRIANGLES);

//Цикл генерацій копій копій полос
while(c2<(Pi2/2)/2)
{
	//Зміщення полосочок
	float ZM = sin(c2); //В кінці забрати двійку
	//Зтягування полосочок в сферу
	Radius1 = cos(c2)  ;
	Radius2 = cos(c2 + 0.1);
	
	//Розраховую правильну ширину полосочок
	float modWid = ((0.1/2) * cos(c2))*1.001;

	c = 0;
	//Створення полос
	while(c<Pi2)
	{
			glColor3f(1,1,1);
			glTexCoord2d(TXsca * (TXtx +	-(c/dilt)),TYtx +		((c2/dilt2	+0.5)*TYsca)		);		 glVertex3f(MeshTX+(MeshSX * (sin(c)*Radius1))	,MeshTY+(MeshSY * (-modWid	+ ZM))	,MeshTZ+(MeshSZ * (cos(c)*Radius1)));  //1
	c+=0.1; glTexCoord2d(TXsca * (TXtx +	-(c/dilt)),TYtx +		((c2/dilt2	+0.5)*TYsca)		);		 glVertex3f(MeshTX+(MeshSX * (sin(c)*Radius1))	,MeshTY+(MeshSY * (-modWid	+ ZM))	,MeshTZ+(MeshSZ * (cos(c)*Radius1))); //2
	c-=0.1; glTexCoord2d(TXsca * (TXtx +	-(c/dilt)),TYtx +		(((c2+0.1)/dilt2 +0.5)*TYsca));			 glVertex3f(MeshTX+(MeshSX * sin(c)*Radius2	)	,MeshTY+(MeshSY * (modWid	+ ZM))	,MeshTZ+(MeshSZ * (cos(c)*Radius2)));  //3 

			glTexCoord2d(TXsca * (TXtx +	-(c/dilt)),TYtx +		(((c2+0.1)/dilt2	 +0.5)*TYsca)	);	 glVertex3f(MeshTX+(MeshSX * sin(c)*Radius2)	,MeshTY+(MeshSY * (modWid	+ ZM))	,MeshTZ+(MeshSZ * (cos(c)*Radius2 )));   //3
	c+=0.1; glTexCoord2d(TXsca * (TXtx +	-(c/dilt)),TYtx +		((c2	/dilt2 +0.5	)*TYsca)		);	 glVertex3f(MeshTX+(MeshSX * sin(c)*Radius1)	,MeshTY+(MeshSY * (-modWid	+ ZM))	,MeshTZ+(MeshSZ * (cos(c)*Radius1 ))); //2
			glTexCoord2d(TXsca * (TXtx +	-(c/dilt)),TYtx +		(((c2+0.1) /dilt2+0.5)*TYsca)	);		 glVertex3f(MeshTX+(MeshSX * sin(c)*Radius2	)	,MeshTY+(MeshSY * (modWid	+ ZM))	,MeshTZ+(MeshSZ * (cos(c)*Radius2 ))); //2
	}
c2+=0.1;
}

glEnd();

//

	}


	void TexturaUS(GLuint IDadresTexture)
	{
		Textura = IDadresTexture;
	}


	~SkyBox()
	{
	}
};
