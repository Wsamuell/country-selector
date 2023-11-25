// module Option = {
//   type t('a);
//   type arg('a) =
//     | Str(string)
//     | Val('a);
//   let encode: arg('a) => t('a) =
//     fun
//     | Str(v) => Obj.magic(v)
//     | Val(v) => Obj.magic(v);
//   let encodeOpt = Belt.Option.map(_, encode);
// };

// module FilterOptions = {
//   type t('a);
//   type sortFunc('a) = (~options: array('a), ~filter: string) => array('a);
//   type arg('a) =
//     | Bool(bool)
//     | Func(sortFunc('a));
//   let encode: arg('a) => t('a) =
//     fun
//     | Bool(v) => Obj.magic(v)
//     | Func(v) => Obj.magic(v);
//   let encodeOpt = Belt.Option.map(_, encode);
// };

module Select = {
  [@bs.module "react-select"];
  [@react.component];

  external make:
    (
      ~multi: bool,
      ~autoBlur: bool=?,
      ~autofocus: bool=?,
      ~autoFocus: bool=?,
      ~autoload: bool=?,
      ~autosize: bool=?,
      ~backspaceRemoves: bool=?,
      ~backspaceToRemoveMessage: string=?,
      ~children: React.element=?,
      ~className: string=?,
      ~clearable: bool=?,
      ~clearAllText: string=?,
      ~clearValueText: string=?,
      ~closeOnSelect: bool=?,
      ~deleteRemoves: bool=?,
      ~delimiter: string=?,
      ~disabled: bool=?,
      ~escapeClearsValue: bool=?,
      ~filterOption: ('a, bool)=?,
      ~filterOptions: ('a, bool)=?, // this type definition is so wrong
      ~id: string=?,
      ~ignoreAccents: bool=?,
      ~ignoreCase: bool=?,
      ~inputProps: Js.t({..})=?, // need to read into this site
      ~instanceId: string=?,
      ~isLoading: bool=?,
      ~joinValues: bool=?,
      ~labelKey: string=?
    ) =>
    //  ~matchPos:[ `any | `start ] =?,
    //  ~matchProp:[ `any | `label | `value ] =?,
    //  ~menuBuffer:int =?,
    //  ~name:string =?,
    //  ~noResultsText:string =?,
    //  ~onBlur:((< .. > as '_weak3) Js.t =?, unit) =?,
    //  ~onBlurResetsInput:bool =?,
    //  ~onChange:('_weak1 Js.nullable =?, unit) =?,
    //  ~onClose:(unit =?, unit) =?,
    //  ~onCloseResetsInput:bool =?,
    //  ~onFocus:(unit =?, unit) =?,
    //  ~onInputChange:(string =?, string) =?,
    //  ~onInputKeyDown:(unit =?, unit) =?,
    //  ~onMenuScrollToBottom:(unit =?, unit) =?,
    //  ~onOpen:(unit =?, unit) =?,
    //  ~onSelectResetsInput:bool =?,
    //  ~onValueClick:('_weak1 =?, (< .. > as '_weak4) Js.t =?, unit) =?,
    //  ~openOnClick:bool =?,
    //  ~openOnFocus:bool =?
    React.element =
    "Select";
};
