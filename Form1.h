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
	/// Form1 est une fenêtre avec des carrés animés
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		// Déclaration du tableau de carrés
		array<CCarre^>^ tabCarre;
		System::Random^ rand; // Instance pour générer des valeurs aléatoires
		int nbcarre; // Nombre de carrés à animer

		Form1(void)
		{
			InitializeComponent();

			// Initialisation du générateur de nombres aléatoires
			rand = gcnew System::Random();

			// Nombre de carrés à animer (par exemple 50)
			nbcarre = 50;

			// Crée le tableau pour stocker les carrés
			tabCarre = gcnew array<CCarre^>(nbcarre);

			// Initialisation des carrés avec des propriétés aléatoires
			for (int i = 0; i < nbcarre; i++)
			{
				tabCarre[i] = gcnew CCarre();

				// Position aléatoire
				tabCarre[i]->Setsx(rand->Next(this->ClientRectangle.Width));
				tabCarre[i]->Setsy(rand->Next(this->ClientRectangle.Height));

				// Taille aléatoire
				tabCarre[i]->SetCote(rand->Next(10, 51));

				// Couleur aléatoire
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

		// Redessiner la fenêtre après le déplacement
		this->Invalidate();
	}

		/// <summary>
		/// Appelé périodiquement pour redessiner les carrés dans la fenêtre
		/// </summary>
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		// Effacer et animer chaque carré du tableau
		// for (int i = 0; i < nbcarre; i++)
		// {
			// Efface le carré à sa position actuelle
			// tabCarre[i]->Effacer(this);

			// Anime chaque carré
			// tabCarre[i]->Animer(this, this->ClientRectangle.Width, this->ClientRectangle.Height);

			// Dessine le carré à sa nouvelle position
			//tabCarre[i]->Dessiner(this);
		// }
	}
	};
}