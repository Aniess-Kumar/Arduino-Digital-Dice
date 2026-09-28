// Compact Arduino Digital Dice enclosure
// Units: mm
// Print: base and lid separately, flat side down.

$fn = 48;

// ---------- Main dimensions ----------
W = 78;       // width
H = 96;       // height
D = 32;       // total depth
wall = 2.4;
base_h = 22;
lid_h = D - base_h;
corner_r = 6;

// Front openings
matrix_w = 34;
matrix_h = 34;
matrix_y = 63;
button_d = 18;
button_y = 22;

// Back USB opening
usb_w = 16;
usb_h = 9;
usb_z = 7;

// ---------- Rounded rectangle 2D ----------
module rounded_rect_2d(w,h,r) {
    hull() {
        translate([r,r]) circle(r);
        translate([w-r,r]) circle(r);
        translate([r,h-r]) circle(r);
        translate([w-r,h-r]) circle(r);
    }
}

// ---------- Base ----------
module base() {
    difference() {
        linear_extrude(base_h)
            rounded_rect_2d(W,H,corner_r);

        // Main internal cavity, leaving bottom thickness
        translate([wall,wall,2.4])
            linear_extrude(base_h)
                rounded_rect_2d(W-2*wall,H-2*wall,max(corner_r-wall,1));

        // Rear USB access opening through back wall
        translate([(W-usb_w)/2, -1, usb_z])
            cube([usb_w, wall+2, usb_h]);
    }
}

// ---------- Lid / front panel ----------
module lid() {
    difference() {
        linear_extrude(lid_h)
            rounded_rect_2d(W,H,corner_r);

        // Matrix window
        translate([(W-matrix_w)/2, matrix_y-matrix_h/2, -1])
            linear_extrude(lid_h+2)
                rounded_rect_2d(matrix_w,matrix_h,2);

        // Push button opening
        translate([W/2,button_y,-1])
            cylinder(d=button_d,h=lid_h+2);
    }
}

// ---------- Print one part at a time ----------
// Change to lid(); for the lid.
base();
