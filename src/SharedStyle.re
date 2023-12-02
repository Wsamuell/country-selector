type color =
  | Light
  | Dark
  | Grey
  | Primary
  | Secondary
  | Hover;

type themeColors = {
  primary: string,
  // primary25: string,
};
type spacing = {
  baseUnit: int,
  controlHeight: int,
  menuGutter: int,
};
let colorToHex = (color: color) =>
  switch (color) {
  | Light => "#FFFFFF"
  | Dark => "#333333"
  | Grey => "#E5E5E5"
  | Primary => "#F2F2F2"
  | Secondary => "#F2F2F2"
  | Hover => "#FFDBB3"
  };
