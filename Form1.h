// Nom du projet : Mes premiers programmes
// Nom de l�auteur : Trompier T�o
// Date de cr�ation : 03/12/2024
// R�sum� : Mes premiers prog fonctions
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
	/// Form1 est une fen�tre avec des carr�s anim�s
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		// D�claration du tableau de carr�s
		array<CCarre^>^ tabCarre;
		System::Random^ rand; // Instance pour g�n�rer des valeurs al�atoires
		int nbcarre; // Nombre de carr�s � animer

		Form1(void)
		{
			InitializeComponent();

			// Initialisation du g�n�rateur de nombres al�atoires
			rand = gcnew System::Random();

			// Nombre de carr�s � animer (par exemple 50)
			nbcarre = 50;

			// Cr�e le tableau pour stocker les carr�s
			tabCarre = gcnew array<CCarre^>(nbcarre);

			// Initialisation des carr�s avec des propri�t�s al�atoires
			for (int i = 0; i < nbcarre; i++)
			{
				tabCarre[i] = gcnew CCarre();

				// Position al�atoire
				tabCarre[i]->Setsx(rand->Next(this->ClientRectangle.Width));
				tabCarre[i]->Setsy(rand->Next(this->ClientRectangle.Height));

				// Taille al�atoire
				tabCarre[i]->SetCote(rand->Next(10, 51));

				// Couleur al�atoire
				int colorChoice = rand->Next(0, 3);
				switch (colorChoice)
				{
				case 0: tabCarre[i]->SetColor(Color::Red); break;
				case 1: tabCarre[i]->SetColor(Color::Green); break;
				case 2: tabCarre[i]->SetColor(Color::Blue); break;
				}
			}

			this->timer1->Enabled = true;

			// Start le timer pour l'animation
			timer1->Start();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
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
		/// Largeur de la fen�tre
		/// </summary>
		int largeur;
		/// <summary>
		/// Hauteur de la fen�tre
		/// </summary>
		int hauteur;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
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

	private: System::Void Form1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		for (int i = 0; i < nbcarre; i++)
		{
			switch (e->KeyCode)
			{
			case Keys::Up:
				tabCarre[i]->Deplacer(0, -5);
				break;
			case Keys::Down:
				tabCarre[i]->Deplacer(0, 5);
				break;
			case Keys::Left:
				tabCarre[i]->Deplacer(-5, 0);
				break;
			case Keys::Right:
				tabCarre[i]->Deplacer(5, 0);
				break;
			}
		}

		// Redessiner la fen�tre apr�s le d�placement
		this->Invalidate();
	}

		/// <summary>
		/// Appel� p�riodiquement pour redessiner les carr�s dans la fen�tre
		/// </summary>
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		// Effacer et animer chaque carr� du tableau
		// for (int i = 0; i < nbcarre; i++)
		// {
			// Efface le carr� � sa position actuelle
			// tabCarre[i]->Effacer(this);

			// Anime chaque carr�
			// tabCarre[i]->Animer(this, this->ClientRectangle.Width, this->ClientRectangle.Height);

			// Dessine le carr� � sa nouvelle position
			//tabCarre[i]->Dessiner(this);
		// }
	}
	};
}