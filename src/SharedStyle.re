type color =
  | Light
  | Dark
  | Grey
  | Primary
  | Secondary
  | Hover;

let colorToHex = (color: color) =>
  switch (color) {
  | Light => "#FFFFFF"
  | Dark => "#000000"
  | Grey => "#E5E5E5"
  | Primary => "#F2F2F2"
  | Secondary => "#F2F2F2"
  | Hover => "#FFDBB3"
  };
