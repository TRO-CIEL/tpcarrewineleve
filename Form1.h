using namespace System;
using namespace System::Drawing;

/// <summary>
/// Carré de couleur
/// </summary>
ref class CCarre
{
private:
    int cote;
    int sx;
    int sy;
    Color color;
    int dx;
    int dy;

public:
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
    /// initialise m_x privé
    /// </summary>
    /// <param name="x">Position x du carré</param>
    void Setsx(int x1)
    {
        sx = x1;
    }

    /// <summary>
    /// retourne m_x privé
    /// </summary>
    /// <returns>Position x du carré</returns>
    int Getsx()
    {
        return sx;
    }

    /// <summary>
    /// initialise m_y privé
    /// </summary>
    /// <param name="y">Position y du carré</param>
    void Setsy(int y1)
    {
        sy = y1;

    }

    /// <summary>
    /// retourne m_y privé
    /// </summary>
    /// <returns>Position y du carré</returns>
    int Getsy()
    {
        return sy;
    }

    /// <summary>
    /// initialise m_color privé
    /// </summary>
    /// <param name="couleur">Couleur du carré</param>
    void SetColor(Color couleur)
    {
        color = couleur;
    }

    /// <summary>
    /// initialise m_cote privé
    /// </summary>
    /// <param name="cote">Coté du carré</param>
    void SetCote(int cote)
    {
        this->cote = cote;
    }

    /// <summary>
    /// retourne m_cote privé
    /// </summary>
    /// <returns>Coté du carré</returns>
    int GetCote()
    {
        return cote;
    }

    /// <summary>
    /// Déplace le carré suivant un vecteur déplacement dx et dy
    /// </summary>
    /// <param name="dx">Valeur dx du déplacement</param>
    /// <param name="dy">Valeur dy du déplacement</param>
    void Deplacer(int dx, int dy)
    {
        sx += dx; // Incrémente la position X
        sy += dy; // Incrémente la position Y
    }

    void Animer(System::Windows::Forms::Form^ form) {
        Effacer(form);

        Deplacer(dx, dy);

        // Si le carré atteint le bord droit ou gauche, on inverse la direction du mouvement
        if (sx < 0 || sx + cote > form->ClientRectangle.Width) {
            dx = -dx;
        }
        // Si le carré atteint le bord haut ou bas, on inverse la direction du mouvement
        if (sy < 0 || sy + cote > form->ClientRectangle.Height) {
            dy = -dy;
        }

        Dessiner(form);
    }

    /// <summary>
    /// Dessine le carré 
    /// </summary>
    /// <param name="form">pointeur sur la fenêtre dans laquelle on dessine.</param>
    void Dessiner(System::Windows::Forms::Form^ form)
    {
        Graphics^ g = form->CreateGraphics();
        g->FillRectangle(gcnew SolidBrush(color), sx, sy, cote, cote);
    }

    /// <summary>
    /// Efface le carré 
    /// </summary>
    /// <param name="form">pointeur sur la fenêtre dans laquelle on dessine.</param>
    void Effacer(System::Windows::Forms::Form^ form)
    {
        Graphics^ g = form->CreateGraphics();
        g->FillRectangle(gcnew SolidBrush(form->BackColor), sx, sy, cote, cote);
    }
};
