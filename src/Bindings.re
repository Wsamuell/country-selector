module Select = {
  type reactSelectComponents = {
    [@mel.as "DropdownIndicator"]
    dropdownIndicator: unit => React.element,
    [@mel.as "IndicatorSeparator"]
    indicatorSeparator: bool,
    // [@mel.as "Control"]
    // control: React.element,
  };

  type styleSelectType = {control: unit => ReactDOMStyle.t};
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
      // ~theme: 'a => record=?,
      ~value: string=?
    ) =>
    React.element =
    "default";
};
