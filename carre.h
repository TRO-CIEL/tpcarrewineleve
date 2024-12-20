// Nom du projet : Mes premiers programmes
// Nom de l�auteur : Trompier T�o
// Date de cr�ation : 03/12/2024
// R�sum� : Mes premiers prog fonctions

using namespace System;
using namespace System::Drawing;

/// <summary>
/// Carr� de couleur
/// </summary>
ref class CCarre
	{
		private :
			
			int cote;
			int sx;
			int sy;
			Color color;
			int dx;
			int dy;
		
		public :
			CCarre()
			{
				sx = 10;
				sy = 10;
				cote = 20;
				color = Color::Red;
				dx = 1;
				dy = 1;
			}

			/// <summary>
			/// initialise m_x priv�
			/// </summary>
			/// <param name="x">Position x du carr�</param>
			void Setsx(int x1)
			{
				sx = x1;
			}

			/// <summary>
			/// retourne m_x priv�
			/// </summary>
			/// <returns>Position x du carr�</returns>
			int Getsx()
			{
				return sx;
			}

			/// <summary>
			/// initialise m_y priv�
			/// </summary>
			/// <param name="y">Position y du carr�</param>
			void Setsy(int y1)
			{
				sy = y1;
				
			}

			/// <summary>
			/// retourne m_y priv�
			/// </summary>
			/// <returns>Position y du carr�</returns>
			int Getsy()
			{
				return sy;
			}


			/// <summary>
			/// initialise m_color priv�
			/// </summary>
			/// <param name="couleur">Couleur du carr�</param>
			void SetColor(Color couleur) 
			{
				color=couleur;
			}

			/// <summary>
			/// initialise m_cote priv�
			/// </summary>
			/// <param name="cote">Cot� du carr�</param>
			void SetCote(int cote)
			{
				cote = cote;
			}

			/// <summary>
			/// retourne m_cote priv�
			/// </summary>
			/// <returns>Cot� du carr�</returns>
			int GetCote() 
			{
				return cote;
			}

			/// <summary>
			/// D�place le carr� suivant un vecteur d�placelent dx et dy
			/// </summary>
			/// <param name="dx">Valeur dx du d�placement</param>
			/// <param name="dy">Valeur dy du d�placement</param>
			void Deplacer(int dx, int dy) 
			{
				sx += dx; // Incr�mente la position X
				sy += dy; // Incr�mente la position Y
			}

			void Animer(System::Windows::Forms::Form^ form, int largeur, int hauteur) {
				// Efface le carr� � la position actuelle
				Effacer(form);

				// D�place le carr� en fonction de dx et dy
				Deplacer(dx, dy);

				// V�rifie les collisions avec les bords de la fen�tre
				if (sx < 0 || sx + cote > largeur) {
					dx = -dx; // Inverse la direction horizontale si le carr� touche un bord
				}
				if (sy < 0 || sy + cote > hauteur) {
					dy = -dy; // Inverse la direction verticale si le carr� touche un bord
				}

			}

			/// <summary>
			/// Dessine le carr� 
			/// </summary>
			/// <param name="form">pointeur sur la fen�tre dans laquelle on dessine.</param>
			void Dessiner(System::Drawing::Graphics^ g);

			/// <summary>
			/// Efface le carr� 
			/// </summary>
			/// <param name="form">pointeur sur la fen�tre dans laquelle on dessine.</param>
			void Effacer(System::Windows::Forms::Form ^form)
			{
				Graphics ^g = form->CreateGraphics();
				g->FillRectangle(gcnew SolidBrush(form->BackColor), sx, sy, cote, cote);
			}
				
	};