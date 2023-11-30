module Select = {
  type optionProps = {children: React.element};
  type reactSelectComponents = {
    [@mel.as "DropdownIndicator"]
    dropdownIndicator: unit => React.element,
    [@mel.as "IndicatorSeparator"]
    indicatorSeparator: bool,
    [@mel.as "Option"]
    option: optionProps => React.element,
  };

  type styleSelectType = {control: ReactDOMStyle.t => ReactDOMStyle.t};
  type themeSelectType = {
    borderRadius: string,
    colors: SharedStyle.themeColors,
    spacing: SharedStyle.spacing,
  };

  [@mel.module "react-select"] [@react.component]
  external make:
    (
      ~autoFocus: bool=?,
      ~backspaceRemovesValue: bool=?,
      ~children: React.element=?,
      ~closeMenuOnSelect: bool=?,
      ~components: reactSelectComponents=?,
      ~controlShouldRenderValue: bool=?,
      ~hideSelectedOptions: bool=?,
      ~isClearable: bool=?,
      ~menuIsOpen: bool=?,
      ~multi: bool,
      ~name: string=?,
      ~noOptionsMessage: 'a => string=?,
      ~onChange: 'a => unit=?,
      ~options: array('a)=?,
      ~placeholder: string=?,
      ~styles: styleSelectType=?,
      ~tabSelectsValue: bool=?,
      ~theme: themeSelectType=?,
      ~value: string=?
    ) =>
    React.element =
    "default";
};
