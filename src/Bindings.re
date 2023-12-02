module Select = {
  type optionProps = {data: CountryData.item};

  type reactSelectComponents = {
    [@mel.as "DropdownIndicator"]
    dropdownIndicator: unit => React.element,
    [@mel.as "IndicatorSeparator"]
    indicatorSeparator: bool,
    [@mel.as "Option"]
    option: optionProps => React.element,
  };

  type styleSelectType = {
    control: ReactDOMStyle.t => ReactDOMStyle.t,
    menu: ReactDOMStyle.t => ReactDOMStyle.t,
    // option: ReactDOMStyle.t => ReactDOMStyle.t,
    // container: ReactDOMStyle.t => ReactDOMStyle.t,
    // indicators: ReactDOMStyle.t => ReactDOMStyle.t,
  };
  type themeSelectType = {
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

  [@mel.scope "components"] [@mel.module "react-select"]
  external makeOptionComponent: optionProps => React.element = "Option";
};

module Option = {
  [@react.component]
  let make = (~props) => props |> Select.makeOptionComponent;
};
