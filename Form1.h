// Nom du projet : Mes premiers programmes
// Nom de l’auteur : Trompier Téo
// Date de création : 03/12/2024
// Résumé : Mes premiers prog fonctions
#pragma once

#include "carre.h"

namespace tpcarrewineleve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 est une fenêtre avec un carré rouge
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		CCarre^ pcarre2;
		Form1(void)
		{
			InitializeComponent();
			//
			// Instanciation dans le tas managé du carré numéro 1 
			pcarre1 = gcnew CCarre();
			pcarre1->SetColor(Color::Red);
			pcarre2 = gcnew CCarre();
			pcarre2->Setsx(100);
			pcarre2->Setsy(100);
			pcarre2->SetCote(30);
			pcarre2->SetColor(Color::Blue);

			// Modifier les attributs sx, sy et cote
			pcarre1->Setsx(100);   // Position en X
			pcarre1->Setsy(150);   // Position en Y
			pcarre1->SetCote(50);  // Taille du carré (longueur du côté)

			this->timer1->Enabled = true;
			largeur = this->ClientRectangle.Width;
			hauteur = this->ClientRectangle.Height;

			timer1->Start();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Le Carré numéro 1.
		/// </summary>
		CCarre^ pcarre1;
		/// <summary>
		/// Largeur de la fenêtre
		/// </summary>
		int largeur;
		/// <summary>
		/// Hauteur de la fenêtre
		/// </summary>
		int hauteur;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 25;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion

		/// <summary>
		/// Appelé périodiquement pour redessiner les carrés dans la fenêtre
		/// </summary>
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		// Efface le carré à sa position actuelle
		pcarre1->Effacer(this);

		// Déplace le carré vers le bas (ajout de 5 pixels en Y)
		pcarre1->Deplacer(0, 5); // dx = 0 (pas de déplacement horizontal), dy = 5 (descente)

		// Dessine le carré à sa nouvelle position
		pcarre1->Dessiner(this);

		// Si le carré dépasse la hauteur de la fenêtre, le repositionner en haut
		if (pcarre1->Getsy() + pcarre1->GetCote() > this->ClientRectangle.Height) {
			pcarre1->Setsy(0); // Repositionne en haut
		}

		pcarre1->Animer(this, this->ClientRectangle.Width, this->ClientRectangle.Height);
		pcarre2->Animer(this, this->ClientRectangle.Width, this->ClientRectangle.Height);
	}
	};
}