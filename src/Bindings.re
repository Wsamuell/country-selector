module Select = {
  type reactSelectComponents = {
    [@mel.as "Control"]
    control: React.element,
    // [@mel.as "Option"]
    // option: React.element,
  };
  [@mel.module "react-select"] [@react.component]
  external make:
    (
      ~children: React.element=?,
      ~closeMenuOnSelect: bool=?,
      ~components: reactSelectComponents=?,
      ~multi: bool,
      ~name: string=?,
      ~noOptionsMessage: 'a => string=?,
      ~onChange: 'a => unit=?,
      ~options: array('a)=?,
      ~placeholder: string=?,
      ~styles: ReactDOM.Style.t=?
    ) =>
    React.element =
    "default";
};
