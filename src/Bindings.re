module Select = {
  type optionProps = {
    data: CountryData.item,
    innerRef: ReactDOM.domRef,
    isFocused: bool,
  };

  //  Read BS BlahBlah to help figure out how to rename fields since each prop can't start with a capital letter
  type reactSelectComponents = {
    [@mel.as "DropdownIndicator"]
    dropdownIndicator: unit => React.element,
    [@mel.as "IndicatorSeparator"]
    indicatorSeparator: bool,
    [@mel.as "Option"]
    option: optionProps => React.element,
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
      ~styles: SharedStyle.styleSelectType=?,
      ~tabSelectsValue: bool=?,
      ~theme: SharedStyle.themeSelectType=?,
      ~value: string=?
    ) =>
    React.element =
    "default";

  // This is a hack to get around the fact that the react-select library doesn't export the Option component: hench more Bs Blah Blah
  [@mel.scope "components"] [@mel.module "react-select"]
  external makeOptionComponent: optionProps => React.element = "Option";
};

module Option = {
  [@react.component]
  let make = (~props) => props |> Select.makeOptionComponent;
};
