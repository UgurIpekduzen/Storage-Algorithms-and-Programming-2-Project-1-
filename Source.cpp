#include"Interface.h"

int main()
{
	Database DB;
	DB.Build();
	Operations OP(&DB);
	Interface IF(&DB,&OP);
	IF.MainOperationsMenu();
	return 0;
}