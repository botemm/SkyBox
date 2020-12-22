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


	//Розмір куба
	float CubSize;
	//Тип текстурк
	short TextureCubeType;



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

			CubSize = 500;


			TextureCubeType = 0;
	}



	void drawSfera()
	{


	//return;
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



glBindTexture(GL_TEXTURE_2D,Textura);
glColor3f(1,1,1);
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
}


	void draw()
	{
		double FixTY = 1.0f/3.0f;



		glBindTexture(GL_TEXTURE_2D,Textura);
		glColor3f(1,1,1);

	if(TextureCubeType == 0)
		{
		drawSfera();
		}
	else
	{
		glBegin(GL_QUADS);

		//1
		glTexCoord2d(0.25,FixTY); glVertex3d(-CubSize,-CubSize,-CubSize);
		glTexCoord2d(0,FixTY); glVertex3d(-CubSize,-CubSize,CubSize);
		glTexCoord2d(0,FixTY*2); glVertex3d(-CubSize,CubSize,CubSize);
		glTexCoord2d(0.25,FixTY*2); glVertex3d(-CubSize,CubSize,-CubSize);

		//2
		glTexCoord2d(0.25,FixTY); glVertex3d(-CubSize,-CubSize,-CubSize);
		glTexCoord2d(0.5,FixTY); glVertex3d(CubSize,-CubSize,-CubSize);
		glTexCoord2d(0.5,FixTY*2); glVertex3d(CubSize,CubSize,-CubSize);
		glTexCoord2d(0.25,FixTY*2); glVertex3d(-CubSize,CubSize,-CubSize);

		//3
		glTexCoord2d(0.50,FixTY); glVertex3d(CubSize,-CubSize,-CubSize);
		glTexCoord2d(0.75,FixTY); glVertex3d(CubSize,-CubSize,CubSize);
		glTexCoord2d(0.75,FixTY*2); glVertex3d(CubSize,CubSize,CubSize);
		glTexCoord2d(0.50,FixTY*2); glVertex3d(CubSize,CubSize,-CubSize);

		//4
		glTexCoord2d(1,FixTY); glVertex3d(-CubSize,-CubSize,CubSize);
		glTexCoord2d(0.75,FixTY); glVertex3d(CubSize,-CubSize,CubSize);
		glTexCoord2d(0.75,FixTY*2); glVertex3d(CubSize,CubSize,CubSize);
		glTexCoord2d(1,FixTY*2); glVertex3d(-CubSize,CubSize,CubSize);
		
		if(TextureCubeType == 1)
		{

		

		//5
		glTexCoord2d(0.25,FixTY*2); glVertex3d(-CubSize,CubSize,-CubSize);
		glTexCoord2d(0.5,FixTY*2); glVertex3d(CubSize,CubSize,-CubSize);
		glTexCoord2d(0.5,1); glVertex3d(CubSize,CubSize,CubSize);
		glTexCoord2d(0.25,1); glVertex3d(-CubSize,CubSize,CubSize);




		//6
		glTexCoord2d(0.25,FixTY); glVertex3d(-CubSize,-CubSize,-CubSize);
		glTexCoord2d(0.5,FixTY);  glVertex3d(CubSize,-CubSize,-CubSize);
		glTexCoord2d(0.5,0);			 glVertex3d(CubSize,-CubSize,CubSize);
		glTexCoord2d(0.25,0);			 glVertex3d(-CubSize,-CubSize,CubSize);
		}
		else
		{
		if(TextureCubeType == 2)
		{

	
		//5
		glTexCoord2d(0.5,1); glVertex3d(-CubSize,CubSize,-CubSize);
		glTexCoord2d(0.5,FixTY*2); glVertex3d(CubSize,CubSize,-CubSize);
		glTexCoord2d(0.75,FixTY*2); glVertex3d(CubSize,CubSize,CubSize);
		glTexCoord2d(0.75,1); glVertex3d(-CubSize,CubSize,CubSize);





		//6
		glTexCoord2d(0.5,0); glVertex3d(-CubSize,-CubSize,-CubSize);
		glTexCoord2d(0.5,FixTY);  glVertex3d(CubSize,-CubSize,-CubSize);
		glTexCoord2d(0.75,FixTY);			 glVertex3d(CubSize,-CubSize,CubSize);
		glTexCoord2d(0.75,0);			 glVertex3d(-CubSize,-CubSize,CubSize);
		}
else
		if(TextureCubeType == 3)
		{


		//5
		glTexCoord2d(1,1); glVertex3d(-CubSize,CubSize,-CubSize);
		glTexCoord2d(0.75,1); glVertex3d(CubSize,CubSize,-CubSize);
		glTexCoord2d(0.75,FixTY*2); glVertex3d(CubSize,CubSize,CubSize);
		glTexCoord2d(1,FixTY*2); glVertex3d(-CubSize,CubSize,CubSize);





		//6
		glTexCoord2d(	1,			0	); glVertex3d(-CubSize,-CubSize,-CubSize);
		glTexCoord2d(	0.75,		0		);  glVertex3d(CubSize,-CubSize,-CubSize);
		glTexCoord2d(	0.75,		FixTY		);			 glVertex3d(CubSize,-CubSize,CubSize);
		glTexCoord2d(	1,			FixTY	);			 glVertex3d(-CubSize,-CubSize,CubSize);
		}
		else
		if(TextureCubeType == 4)
		{

		

		//5
		glTexCoord2d(0.25,(FixTY*2)); glVertex3d(-CubSize,CubSize,-CubSize);
		glTexCoord2d(0.25,1); glVertex3d(CubSize,CubSize,-CubSize);
		glTexCoord2d(0,1); glVertex3d(CubSize,CubSize,CubSize);
		glTexCoord2d(0,(FixTY*2)); glVertex3d(-CubSize,CubSize,CubSize);





		//6
		glTexCoord2d(0.25,FixTY); glVertex3d(-CubSize,-CubSize,-CubSize);
		glTexCoord2d(0.25,0);  glVertex3d(CubSize,-CubSize,-CubSize);
		glTexCoord2d(0,0);			 glVertex3d(CubSize,-CubSize,CubSize);
		glTexCoord2d(0,FixTY);			 glVertex3d(-CubSize,-CubSize,CubSize);
		}
		

		}
		glEnd();
		}
	}

	void TexturaUS(GLuint IDadresTexture)
	{
		Textura = IDadresTexture;
	}


	~SkyBox()
	{
	}
};
