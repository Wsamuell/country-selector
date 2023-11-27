module Select = {
  [@mel.module "react-select"] [@react.component]
  external make:
    (
      ~multi: bool,
      ~options: array('a)=?,
      ~name: string=?,
      ~noResultsText: string=?,
      ~placeholder: string=?
    ) =>
    React.element =
    "default";
};
