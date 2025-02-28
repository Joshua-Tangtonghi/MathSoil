#include "Camera.h"
#include <math.h>


Camera::Camera()
{
    deltaForward = 0;
    deltaStrafe = 0;

    posx = 0.0f;
    posy = 1.5f;
    posz = 5.0f;

    dirx = 0.0f;
    diry = 0.0f;
    dirz = -1.0f;

    angleh = 0.0f;
    anglev = 0.0f;

    xOrigin = -1;
    yOrigin = -1;

    deltaAnglex = 0.0f;
    deltaAngley = 0.0f;



    locked = 1;
}

void Camera::updatePos()
{
    if (deltaForward || deltaStrafe)
    {
        if (locked)
        {
            posx += deltaForward * (dirx/cos(anglev + deltaAngley)) * MOVE_SPEED;
            posy = 1.5f;
            posz += deltaForward * (dirz/cos(anglev + deltaAngley)) * MOVE_SPEED;
            posx += deltaStrafe * (dirz/cos(anglev + deltaAngley)) * MOVE_SPEED;
            posz -= deltaStrafe * (dirx/cos(anglev + deltaAngley)) * MOVE_SPEED;

        }
        else
        {
            posx += deltaForward * dirx * MOVE_SPEED;
            posy += deltaForward * diry * MOVE_SPEED;
            posz += deltaForward * dirz * MOVE_SPEED;
            posx += deltaStrafe * dirz * MOVE_SPEED;
            posz -= deltaStrafe * dirx * MOVE_SPEED;
        }
    }
}

void Camera::orienterCam(int x, int y)
{
    if (xOrigin >= 0)
    {
        // Calcul de l'angle horizontal
        deltaAnglex = (x - xOrigin) * SENSIBILITY;
        // Correction de l'angle ]-Pi; Pi[
        while (deltaAnglex + angleh > M_PI)
            deltaAnglex -= M_PI * 2;
        while (deltaAnglex + angleh < -M_PI)
            deltaAnglex += M_PI * 2;

        // Calcul de l'angle vertical
        deltaAngley = (y - yOrigin) * SENSIBILITY;
        // Limitation de l'angle (limite haute)
        if (deltaAngley + anglev > M_PI_2)
            deltaAngley = M_PI_2 - anglev - 0.01f;
        // Limitation de l'angle (limite basse)
        if (deltaAngley + anglev < -M_PI_2)
            deltaAngley = -M_PI_2 - anglev + 0.01f;

        // Mis � jour de la cam�ra
        dirx = sin(angleh + deltaAnglex)*cos(anglev + deltaAngley);
        diry = -sin(anglev + deltaAngley);
        dirz = -cos(angleh + deltaAnglex)*cos(anglev + deltaAngley);
    }
}
void Camera::releaseCam()
{
    angleh += deltaAnglex;
    anglev += deltaAngley;

    yOrigin = -1;
    xOrigin = -1;
}
void Camera::grabCam(int x, int y)
{
    xOrigin = x;
    yOrigin = y;
}
