type color =
  | Light
  | Dark
  | Grey
  | Primary
  | Secondary
  | Hover
  | TesterColor;

type themeColors = {
  primary25: string, // menu onHover or onSelected color
  neutral50: string, // placeholder text color
  neutral80: string // input text color
};

type spacing = {
  baseUnit: int,
  controlHeight: int,
};
let colorToHex = (color: color) =>
  switch (color) {
  | Light => "#FFFFFF"
  | Dark => "#333333"
  | Grey => "#E5E5E5"
  | Primary => "#F2F2F2"
  | Secondary => "#F2F2F2"
  | Hover => "#FFDBB3"
  | TesterColor => "#79FF9A"
  };

type styleSelectType = {
  control: ReactDOMStyle.t => ReactDOMStyle.t,
  menu: ReactDOMStyle.t => ReactDOMStyle.t,
};
type themeSelectType = {
  colors: themeColors,
  spacing,
};
