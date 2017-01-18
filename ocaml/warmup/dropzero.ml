(* drop a particular value, in this case 0, from a list of integers *)
let rec dropzero lst = 
  match lst with
  | [] -> []
  | h::t -> if (h = 0) then t else h::(dropzero t);;

(* helper function: to print a list *)
let print_lst lst = 
  print_string "[ ";
  List.iter (fun x -> Printf.printf "%d " x) lst;
  print_string "]\n";;

(* test program *)
let () = 
  let l1 = [0;1;2;3;4;5;6] in 
  begin
    print_string "the original list: \n";
    print_lst l1;
    print_string "\nafter dropping 0 from the list: \n";
    print_lst (dropzero l1)
  end
