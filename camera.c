#include "scene.h"

t_camera        camera(t_canvas *canvas, t_point orig, double view_h, double focal_len)
{
    t_camera    cam;

    cam.orig = orig;
    cam.view_h = view_h;
    cam.view_w = view_h * canvas->aspect_ratio;
    cam.focal_len = focal_len;
    cam.horizontal = vec(cam.view_w, 0, 0);
    cam.vertical = vec(0, cam.view_h, 0);

    cam.left_bottom = vminus(vminus(vminus(cam.orig, vdivide(cam.horizontal, 2)), vdivide(cam.vertical, 2)), vec(0, 0, focal_len));

    return (cam);
}