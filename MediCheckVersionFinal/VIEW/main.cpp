#include "frmPrincipal.h"
#include "frmVerificador.h"




using namespace System;
using namespace System::Windows::Forms;
using namespace VIEW;

void main(array <String^>^ args)

{

	//Application::EnableVisualStyles();

	//Application::SetCompatibleTextRenderingDefault(false);



	//frmPrincipal ventana; /*Estoy creando el objeto ventana que va a ser del tipo frmPrincipal*/

	//Application::Run(% ventana); //Aqui estoy ejecutando la ventana inicial
   
    //Cambio para crear el modulo de Log In
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    frmVerificador login;

    // Mostrar login como ventana modal
    if (login.ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        frmPrincipal ventana;
        Application::Run(% ventana);
    }
	

}