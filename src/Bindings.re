module Select = {
  [@mel.module "react-select"] [@react.component]
  external make:
    (
      ~arrowRenderer: 'a => React.element=?,
      ~closeMenuOnSelect: bool=?,
      ~multi: bool,
      ~name: string=?,
      ~noOptionsMessage: 'a => string=?,
      ~onChange: 'a => unit=?,
      ~options: array('a)=?,
      ~placeholder: string=?,
      ~styles: ReactDOM.Style.t=?,
      ~wrapperStyle: ReactDOM.Style.t=?
    ) =>
    React.element =
    "default";
};

module Flag = {
  [@mel.module "flag-icons"] [@react.component]
  external make: (~countryCode: string) => React.element = "default";
};
